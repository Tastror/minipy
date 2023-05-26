#include <iostream>
#include <string>
#include <functional>

#include "common.h"
#include "color.h"

#include "log.h"

namespace Log {

    stage log_stage = stage::debug;
    bool add_time = false;

    void endl(placeholder p) { std::cout << std::endl; }
    void flush(placeholder p) { std::cout << std::flush; }

    void std(const std::string& str) {
        std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
        std::cout << time_str + str;
    }

    void debug(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::debug)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << hue::grey << time_str + "debug: " + str << hue::reset;
        }
    }

    void info(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::info)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << hue::aqua << time_str + "info: " + str << hue::reset;
        }
    }

    void warning(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::warning)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << hue::yellow << time_str + "warning: " + str << hue::reset;
        }
    }

    void error(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::error)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << hue::red << time_str + "error: " + str << hue::reset;
        }
    }
}


LoggerType::LoggerType() {
    log_func = Log::info;
}

LoggerType& LoggerType::operator<<(void (&log_function)(const std::string &str)) {
    log_func = log_function;
    return *this;
}

LoggerType& LoggerType::operator<<(void (&ost)(Log::placeholder)) {
    log_func(ss.str());
    ost(Log::placeholder());
    ss.str(std::string());
    return *this;
}

LoggerType Logger;
