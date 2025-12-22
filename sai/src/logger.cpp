#include "logger.h"
#include <syslog.h>
#include <iostream>
#include "sai.h"

int logger::log_level = SAI_LOG_LEVEL_NOTICE;

// For test purpose, print log to console when set to true, default false.
bool logger::is_debug = false;

void
logger::init()
{
    static bool initialized = false;
    if (!initialized)
    {
        openlog("syncd", LOG_PID | LOG_CONS, LOG_USER);
        initialized = true;
    }
}

void
logger::uninit()
{
    // Always safe to call
    closelog();
}

void
logger::debug(const std::string& msg)
{
    log(SAI_LOG_LEVEL_DEBUG, msg);
}

void
logger::info(const std::string& msg)
{
    log(SAI_LOG_LEVEL_INFO, msg);
}

void
logger::notice(const std::string& msg)
{
    log(SAI_LOG_LEVEL_NOTICE, msg);
}

void
logger::warn(const std::string& msg)
{
    log(SAI_LOG_LEVEL_WARN, msg);
}

void
logger::error(const std::string& msg)
{
    log(SAI_LOG_LEVEL_ERROR, msg);
}

void
logger::critical(const std::string& msg)
{
    log(SAI_LOG_LEVEL_CRITICAL, msg);
}

void
logger::log(int level, const std::string& msg)
{
    if (is_debug) {
        std::string level_str = level == SAI_LOG_LEVEL_CRITICAL ? "CRITICAL" :
                                (level == SAI_LOG_LEVEL_ERROR ? "ERROR" :
                                (level == SAI_LOG_LEVEL_WARN ? "WARN" :
                                (level == SAI_LOG_LEVEL_NOTICE ? "NOTICE" :
                                (level == SAI_LOG_LEVEL_INFO ? "INFO" : "DEBUG"))));
        std::cout << level_str << ":" << msg << std::endl;
        return;
    }

    init();

    if (level < log_level) {
        return;
    }

    int priority = level == SAI_LOG_LEVEL_CRITICAL ? LOG_CRIT :
                   (level == SAI_LOG_LEVEL_ERROR ? LOG_ERR :
                   (level == SAI_LOG_LEVEL_WARN ? LOG_WARNING :
                   (level == SAI_LOG_LEVEL_NOTICE ? LOG_NOTICE :
                   (level == SAI_LOG_LEVEL_INFO ? LOG_INFO : LOG_DEBUG))));
    // Log the message with the specified priority
    syslog(priority, "%s", msg.c_str());
}
