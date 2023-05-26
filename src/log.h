#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <functional>

namespace Log {
    enum class stage {error, warning, info, debug};
    enum class placeholder {};

    extern stage log_stage;
    extern bool add_time;

    void endl(placeholder p);
    void flush(placeholder p);

    void std(const std::string& str);
    void debug(const std::string& str);
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
}

class LoggerType {
private:
    std::function<void(const std::string&)> log_func;
    std::stringstream ss;
public:
    LoggerType();

    // template implement should be set in the .h file
    template<class T> LoggerType& operator<<(const T& data) {
        ss << data;
        return *this;
    }

    LoggerType& operator<<(void (&log_function)(const std::string &str));
    LoggerType& operator<<(void (&ost)(Log::placeholder));
};

extern LoggerType Logger;