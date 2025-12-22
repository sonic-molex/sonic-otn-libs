// virtual_platform.h
#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>
#include "virtual_device.h"
#include "logger.h"

class virtual_platform {
public:
    static virtual_platform& instance() {
        static virtual_platform inst;
        return inst;
    }
   
    // Template-based create function
    template <typename T>
    T* create_device(const std::string& name);

    // Template-based getter
    template <typename T>
    T* get_device(const std::string& name);

    // Count devices of a specific type
    template<typename T>
    size_t count_devices_of_type () const;
    

private:
    
    virtual_platform() = default;
    ~virtual_platform() = default;

    // Disable copy/move
    virtual_platform(const virtual_platform&) = delete;
    virtual_platform& operator=(const virtual_platform&) = delete;
    virtual_platform(virtual_platform&&) = delete;
    virtual_platform& operator=(virtual_platform&&) = delete;

    std::unordered_map<std::string, std::unique_ptr<virtual_device_base>> devices;
};


// Template create_device
template <typename T>
T* virtual_platform::create_device(const std::string& name) {
    static_assert(std::is_base_of<virtual_device_base, T>::value,
                    "T must inherit from virtual_device_base");

    auto it = devices.find(name);
    if (it != devices.end()) {
        logger::notice(std::string(__func__) + ", Device " + name + " already exists");
        return dynamic_cast<T*>(it->second.get());
    }

    auto dev = std::make_unique<T>(name);
    T* dev_ptr = dev.get();
    devices[name] = std::move(dev);

    logger::notice(std::string(__func__) + ", Created device " + name);

    return dev_ptr;
}

// Generic device lookup
template <typename T>
T* virtual_platform::get_device(const std::string& name) {
    auto it = devices.find(name);
    if (it == devices.end())
        return nullptr;
    return dynamic_cast<T*>(it->second.get());
}


template<typename T>
size_t virtual_platform::count_devices_of_type () const {
    size_t count = 0;
    for (const auto& pair : devices) {
        if (dynamic_cast<T*>(pair.second.get()) != nullptr) {
            ++count;
        }
    }
    return count;
}
