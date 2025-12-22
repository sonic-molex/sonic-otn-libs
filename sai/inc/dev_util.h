#pragma once

#include <map>
#include <string>

class dev_util
{
public:
    static uint32_t get_dev_type(const std::string &name);
    static uint32_t get_dev_index(const std::string &name);
    static uint32_t get_sub_index(const std::string &name);

private:
    static std::map<std::string, uint32_t> dev_map;
};
