#pragma once

#include <string>
#include <map>

class LedConvert
{
public:
    static int32_t ColorToState(const std::string &color);
    static std::string StateToColor(int32_t state);

private:
    static const std::map<int32_t, std::string> m_leds;
};

class TempConvert
{
public:
    static double IntToFloat(int32_t value);
    static int32_t FloatToInt(double value);
    static int32_t m_weight;
};

class PowerConvert
{
public:
    static double IntToFloat(int32_t value);
    static int32_t FloatToInt(double value);
    static int32_t m_weight;
};

class FanConvert
{
public:
    static std::string StateToDirect(int32_t state);

private:
    static const std::map<int32_t, std::string> m_fans;
};

class ModuleConvert
{
public:
    static std::string TypeToStr(int32_t type);
    static std::string StateToStr(int32_t type);
private:
    static const std::map<int32_t, std::string> m_types;
    static const std::map<int32_t, std::string> m_states;
};