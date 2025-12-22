#pragma once

#include <string>

class logger
{
public:
    static void init(void);
    static void uninit(void);
    static void debug(const std::string& msg);
    static void info(const std::string& msg);
    static void notice(const std::string& msg);
    static void warn(const std::string& msg);
    static void error(const std::string& msg);
    static void critical(const std::string& msg);

    static int log_level;

    // For test purpose, print log to console when set to true, default false.
    static bool is_debug;

private:
    static void log(int level, const std::string& msg);
};
