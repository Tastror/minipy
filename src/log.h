#pragma once

#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>
#include <functional>

#include "common.h"
#include "color.h"

namespace stdlog {
    
    enum stage {error, warning, std, info, debug};
    enum operat {endl, flush, to_stdout, to_file, to_stdout_and_file};
    enum timeadd {add_time, no_time};
    extern stage log_stage;

    class LogType {
    private:
        bool use_file;
        bool use_stdout;
        bool add_time;

        std::ostream* output_console;
        std::ofstream* of;
        std::set<std::ofstream*> tmp;
        std::function<void(const std::string&)> log_func;

        std::stringstream ss;
        stdlog::stage last_stage;

        void error(const std::string& str);
        void warning(const std::string& str);
        void std(const std::string& str);
        void info(const std::string& str);
        void debug(const std::string& str);
        
    public:

        LogType();

        void change_output_file(std::ofstream&);

        void add_temp_output_file(std::ofstream&);
        void del_all_temp_output_file();

        // template implement should be set in the .h file
        template<class T> LogType& operator<<(const T& data) {
            ss << data;
            return *this;
        }

        LogType& operator<<(stdlog::operat);
        LogType& operator<<(stdlog::stage);
        LogType& operator<<(stdlog::timeadd);
    };

    extern LogType log;
}