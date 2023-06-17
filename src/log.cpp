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

void LoggerType::change_output_file(std::ofstream& f) {
    of = &f;
}

void LoggerType::add_temp_output_file(std::ofstream& f) {
    tmp.insert(&f);
}

void LoggerType::del_all_temp_output_file() {
    tmp.clear();
    tmp = decltype(tmp)();  // free the capacity
}


LoggerType& LoggerType::operator<<(Log::operat op) {
    switch (op) {
    case Log::endl:
        log_func(ss.str());
        ss.str(std::string());
        // error will always output on stdin !!!
        if (use_stdin || last_stage == Log::error)
            std::cout << std::endl;
        if (use_file) {
            *of << std::endl;
            for (auto& i : tmp)
                *i << std::endl;
        }
        break;
    case Log::flush:
        log_func(ss.str());
        ss.str(std::string());
        // error will always output on stdin !!!
        if (use_stdin || last_stage == Log::error)
            std::cout << std::flush;
        if (use_file) {
            *of << std::flush;
            for (auto& i : tmp)
                *i << std::flush;
        }
        break;
    case Log::to_stdout:
        use_stdin = true;
        use_file = false;
        break;
    case Log::to_file:
        use_stdin = false;
        use_file = true;
        break;
    case Log::to_stdout_and_file:
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

void LoggerType::debug(const std::string& str) {
    last_stage = Log::debug;
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::debug)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << GREEN << time_str << PURPLE << "debug: " + str << RESET;
        if (use_file) {
            *of << time_str + "debug: " + str;
            for (auto& i : tmp)
                *i << time_str + "debug: " + str;
        }
    }
}

void LoggerType::info(const std::string& str) {
    last_stage = Log::info;
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::info)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << GREEN << time_str << CYAN << "info: " + str << RESET;
        if (use_file) {
            *of << time_str + "info: " + str;
            for (auto& i : tmp)
                *i << time_str + "info: " + str;
        }
    }
}

void LoggerType::std(const std::string& str) {
    last_stage = Log::std;
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::std)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << GREEN << time_str << RESET << str << RESET;
        if (use_file) {
            *of << time_str + str;
            for (auto& i : tmp)
                *i << time_str + str;
        }
    }
}

void LoggerType::warning(const std::string& str) {
    last_stage = Log::warning;
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::warning)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        if (use_stdin)
            std::cout << GREEN << time_str << YELLOW << "warning: " + str << RESET;
        if (use_file) {
            *of << time_str + "warning: " + str;
            for (auto& i : tmp)
                *i << time_str + "warning: " + str;
        }
    }
}

void LoggerType::error(const std::string& str) {
    last_stage = Log::error;
    if (unsigned(Log::log_stage) >= unsigned(Log::stage::error)) {
        std::string time_str = Log::add_time ? "[" + timing::local_time() + "] " : "";
        // error will always output on stdin !!!
        std::cout << GREEN << time_str << RED << "error: " + str << RESET;
        if (use_file) {
            *of << time_str + "error: " + str;
            for (auto& i : tmp)
                *i << time_str + "error: " + str;
        }
    }
}

LoggerType Logger;
