#pragma once

#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>
#include <functional>

#include "timing.h"
#include "color.h"

namespace stdlog {
    
    enum stage {error, warning, std, info, debug};
    enum operat {endl, flush};
    enum target {stdout_on, stdout_off, file_on, file_off, temp_files_on, temp_files_off};
    enum timeadd {add_time, no_time};
    extern stage log_stage;

    class logstream {
    private:
        bool use_stdout;
        bool use_file;
        bool use_temp_files;
        bool use_add_time;

        std::ostream* output_console;
        std::ofstream* output_file;
        std::set<std::ofstream*> temp_output_files_set;
        std::function<void(const std::string&)> log_func;

        std::stringstream ss;
        stdlog::stage last_stage;

        void log_error(const std::string& str);
        void log_warning(const std::string& str);
        void log_std(const std::string& str);
        void log_info(const std::string& str);
        void log_debug(const std::string& str);
        
    public:

        logstream();

        void change_output_console(std::ostream&);
        void change_output_file(std::ofstream&);
        void add_temp_output_file(std::ofstream&);
        void del_all_temp_output_file();

        // template implement should be set in the .h file
        template<class T> logstream& operator<<(const T& data) {
            ss << data;
            return *this;
        }

        logstream& operator<<(stdlog::stage);
        logstream& operator<<(stdlog::operat);
        logstream& operator<<(stdlog::target);
        logstream& operator<<(stdlog::timeadd);
    };

    extern logstream log;
}