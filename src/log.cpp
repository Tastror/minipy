#include <iostream>
#include <string>
#include <functional>

#include "common.h"
#include "color.h"

#include "log.h"

namespace Log {
    stage log_stage = stage::debug;
    bool add_time = false;
}


LoggerType::LoggerType() {
    use_file = false;
    use_stdin = true;
    log_func = std::bind(&LoggerType::debug, this, std::placeholders::_1);
}

void LoggerType::add_output_file(std::ofstream& f) {
    of = &f;
}

void LoggerType::debug(const std::string& str) {
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::debug)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << hue::grey << time_str + "debug: " + str << hue::reset;
        if (use_file)
            *of << time_str + "debug: " + str;
    }
}

void LoggerType::info(const std::string& str) {
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::info)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << hue::aqua << time_str + "info: " + str << hue::reset;
        if (use_file)
            *of << time_str + "info: " + str;
    }
}

void LoggerType::std(const std::string& str) {
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::std)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << hue::reset << time_str + str << hue::reset;
        if (use_file)
            *of << time_str + str;
    }
}

void LoggerType::warning(const std::string& str) {
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::warning)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << hue::yellow << time_str + "warning: " + str << hue::reset;
        if (use_file)
            *of << time_str + "warning: " + str;
    }
}

void LoggerType::error(const std::string& str) {
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::error)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << hue::red << time_str + "error: " + str << hue::reset;
        if (use_file)
            *of << time_str + "error: " + str;
    }
}

LoggerType& LoggerType::operator<<(Log::operat op) {
    switch (op) {
    case Log::endl:
        log_func(ss.str());
        ss.str(std::string());
        if (use_stdin)
            std::cout << std::endl;
        if (use_file)
            *of << std::endl;
        break;
    case Log::flush:
        log_func(ss.str());
        ss.str(std::string());
        if (use_stdin)
            std::cout << std::flush;
        if (use_file)
            *of << std::flush;
        break;
    case Log::to_stdin:
        use_stdin = true;
        use_file = false;
        break;
    case Log::to_file:
        use_stdin = false;
        use_file = true;
        break;
    case Log::stdin_and_file:
        use_stdin = use_file = true;
        break;
    default:
        break;
    }
    return *this;
}

LoggerType& LoggerType::operator<<(Log::stage st) {
    switch (st) {
    case Log::error:
        log_func = std::bind(&LoggerType::error, this, std::placeholders::_1);
        break;
    case Log::warning:
        log_func = std::bind(&LoggerType::warning, this, std::placeholders::_1);
        break;
    case Log::std:
        log_func = std::bind(&LoggerType::std, this, std::placeholders::_1);
        break;
    case Log::info:
        log_func = std::bind(&LoggerType::info, this, std::placeholders::_1);
        break;
    case Log::debug:
        log_func = std::bind(&LoggerType::debug, this, std::placeholders::_1);
        break;
    default:
        log_func = std::bind(&LoggerType::std, this, std::placeholders::_1);
        break;
    }
    return *this;
}

LoggerType Logger;
