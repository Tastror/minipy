#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>
#include <functional>

namespace Log {
    enum stage {error, warning, std, info, debug};
    enum operat {endl, flush, to_stdin, to_file, stdin_and_file};
    extern stage log_stage;
    extern bool add_time;
}

class LoggerType {
private:
    std::function<void(const std::string&)> log_func;
    std::stringstream ss;
    std::ofstream* of;
    bool use_file;
    bool use_stdin;

public:

    LoggerType();

    void add_output_file(std::ofstream&);

    void std(const std::string& str);
    void debug(const std::string& str);
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);


    // template implement should be set in the .h file
    template<class T> LoggerType& operator<<(const T& data) {
        ss << data;
        return *this;
    }

    LoggerType& operator<<(Log::operat);
    LoggerType& operator<<(Log::stage);
};

extern LoggerType Logger;