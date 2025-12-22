#include "Convert.h"
#include "HalPlatformData.h"
#include <math.h>
#include "virtual_device.h"

const std::map<int32_t, std::string> LedConvert::m_leds = {
    {static_cast<int32_t>(virtual_device_base::Led_Status::OFF), "off"},
    {static_cast<int32_t>(virtual_device_base::Led_Status::RED), "red"},
    {static_cast<int32_t>(virtual_device_base::Led_Status::GREEN), "green"},
    {static_cast<int32_t>(virtual_device_base::Led_Status::AMBER), "amber"},
    {static_cast<int32_t>(virtual_device_base::Led_Status::RED_BLINK), "red blink"},
    {static_cast<int32_t>(virtual_device_base::Led_Status::GREEN_BLINK), "green blink"},
    {static_cast<int32_t>(virtual_device_base::Led_Status::AMBER_BLINK), "amber blink"}
};

int32_t TempConvert::m_weight = 10;
int32_t PowerConvert::m_weight = 100;


const std::map<int32_t, std::string> FanConvert::m_fans = {
    {static_cast<int32_t>(virtual_fan_device::FAN_DIRECTION::INTAKE), "FAN_DIRECTION_INTAKE"},
    {static_cast<int32_t>(virtual_fan_device::FAN_DIRECTION::EXHAUST), "FAN_DIRECTION_EXHAUST"}
};

const std::map<int32_t, std::string> ModuleConvert::m_types = {
    {static_cast<int32_t>(virtual_module_device::Module_Type::MODULE_TYPE_SUPERVISOR), "SUPERVISOR"},
    {static_cast<int32_t>(virtual_module_device::Module_Type::MODULE_TYPE_LINECARD), "LINE-CARD"},
    {static_cast<int32_t>(virtual_module_device::Module_Type::MODULE_TYPE_FABRIC), "FABRIC-CARD"}
};
const std::map<int32_t, std::string> ModuleConvert::m_states = {
    {static_cast<int32_t>(virtual_device_base::Slot_State::OFFLINE), "Offline"},
    {static_cast<int32_t>(virtual_device_base::Slot_State::ONLINE), "Online"},
    {static_cast<int32_t>(virtual_device_base::Slot_State::MISMATCH), "Fault"}
};

template<typename T1, typename T2>
T2
__FindMap(T1 k, const std::map<T1, T2> &m)
{
    if (m.find(k) == m.end()) {
        return DEF_COMPONENT_NAME_NA;
    }
    return m.find(k)->second;
}

int32_t
LedConvert::ColorToState(const std::string &color)
{
    for (auto &led : m_leds) {
        if (color == led.second ) {
            return led.first;
        }
    }
    return DEF_RETURN_NONE;
}

std::string
LedConvert::StateToColor(int state)
{
    return __FindMap(state, m_leds);
}

double
TempConvert::IntToFloat(int32_t value)
{
    return (double)value / m_weight;
}

int32_t
TempConvert::FloatToInt(double value)
{
    return (int32_t)round(value * m_weight);
}

double
PowerConvert::IntToFloat(int32_t value)
{
    return (double)value / m_weight;
}

int32_t
PowerConvert::FloatToInt(double value)
{
    return (int32_t)round(value * m_weight);
}

std::string
FanConvert::StateToDirect(int32_t state)
{
    return __FindMap(state, m_fans);
}

std::string
ModuleConvert::TypeToStr(int32_t type)
{
    return __FindMap(type, m_types);
}

std::string
ModuleConvert::StateToStr(int32_t type)
{
    return __FindMap(type, m_states);
}