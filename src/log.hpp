#pragma once

#include <iostream>
#include <string>
#include <functional>

#include "./common.hpp"
#include "./color-console/include/color.hpp"

namespace Log {

    enum class stage {error, warning, info, debug};

    stage log_stage = stage::debug;
    bool add_time = false;

    void endl() {}

    void debug(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::debug)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << dye::grey(time_str + "debug: " + str) << std::endl;
        }
    }

    void output(const std::string& str) {
        std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
        std::cout << time_str + str << std::endl;
    }

    void info(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::info)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << dye::aqua(time_str + "info: " + str) << std::endl;
        }
    }

    void warning(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::warning)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << dye::yellow(time_str + "warning: " + str) << std::endl;
        }
    }

    void error(const std::string& str) {
        if (unsigned(log_stage) >= unsigned(stage::error)) {
            std::string time_str = add_time ? "[" + timing::local_time() + "] " : "";
            std::cout << dye::red(time_str + "error: " + str) << std::endl;
        }
    }
}

class LoggerType {
private:
    std::function<void(const std::string&)> log_func = Log::info;
    std::stringstream ss;

public:
    template<class T> LoggerType& operator<<(const T& data) {
        ss << data;
        return *this;
    }

    LoggerType& operator<<(void (&log_function)(const std::string &str)) {
        log_func = log_function;
        return *this;
    }

    LoggerType& operator<<(void (&endl)()) {
        log_func(ss.str());
        ss.str(std::string());
        return *this;
    }
};

LoggerType Logger;