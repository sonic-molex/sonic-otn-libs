#pragma once

#include <string>

typedef enum _platform_log_level_t
{
    /** Log Level Debug */
    PLATFORM_LOG_LEVEL_DEBUG            = 0,
    /** Log Level Info */
    PLATFORM_LOG_LEVEL_INFO             = 1,
    /** Log Level Notice */
    PLATFORM_LOG_LEVEL_NOTICE           = 2,
    /** Log level Warning */
    PLATFORM_LOG_LEVEL_WARN             = 3,
    /** Log Level Error */
    PLATFORM_LOG_LEVEL_ERROR            = 4,
    /** Log Level Critical */
    PLATFORM_LOG_LEVEL_CRITICAL         = 5

} platform_log_level_t;

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
