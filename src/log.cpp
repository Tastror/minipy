#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>
#include <functional>
#include <regex>

#include "timing.h"
#include "color.h"
#include "log.h"

namespace stdlog {
    stage log_stage = debug;

    void logstream::log_error(const std::string& str) {
        std::string str_with_no_033m = std::regex_replace(str, std::regex("\033\\[.*?m"), "");
        last_stage = error;
        if (unsigned(log_stage) >= unsigned(error)) {
            std::string time_str = use_add_time ? "[" + timing::local_time() + "] " : "";
            if (true)  // error will always output to stdout
                *output_console << GREEN << time_str << RED << "error: " + str << RESET;
            if (use_file)
                *output_file << time_str + "error: " + str_with_no_033m;
            if (use_temp_files)
                for (auto& i : temp_output_files_set)
                    *i << time_str + "error: " + str_with_no_033m;
        }
    }

    void logstream::log_warning(const std::string& str) {
        std::string str_with_no_033m = std::regex_replace(str, std::regex("\033\\[.*?m"), "");
        last_stage = warning;
        if (unsigned(log_stage) >= unsigned(warning)) {
            std::string time_str = use_add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdout)
                *output_console << GREEN << time_str << YELLOW << "warning: " + str << RESET;
            if (use_file)
                *output_file << time_str + "warning: " + str_with_no_033m;
            if (use_temp_files)
                for (auto& i : temp_output_files_set)
                    *i << time_str + "warning: " + str_with_no_033m;
        }
    }
    
    void logstream::log_std(const std::string& str) {
        std::string str_with_no_033m = std::regex_replace(str, std::regex("\033\\[.*?m"), "");
        last_stage = std;
        if (unsigned(log_stage) >= unsigned(std)) {
            std::string time_str = use_add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdout)
                *output_console << GREEN << time_str << RESET << str << RESET;
            if (use_file)
                *output_file << time_str + str_with_no_033m;
            if (use_temp_files)
                for (auto& i : temp_output_files_set)
                    *i << time_str + str_with_no_033m;
        }
    }

    void logstream::log_info(const std::string& str) {
        std::string str_with_no_033m = std::regex_replace(str, std::regex("\033\\[.*?m"), "");
        last_stage = info;
        if (unsigned(log_stage) >= unsigned(info)) {
            std::string time_str = use_add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdout)
                *output_console << GREEN << time_str << CYAN << "info: " + str << RESET;
            if (use_file)
                *output_file << time_str + "info: " + str_with_no_033m;
            if (use_temp_files)
                for (auto& i : temp_output_files_set)
                    *i << time_str + "info: " + str_with_no_033m;
        }
    }

    void logstream::log_debug(const std::string& str) {
        std::string str_with_no_033m = std::regex_replace(str, std::regex("\033\\[.*?m"), "");
        last_stage = debug;
        if (unsigned(log_stage) >= unsigned(debug)) {
            std::string time_str = use_add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdout)
                *output_console << GREEN << time_str << PURPLE << "debug: " + str << RESET;
            if (use_file)
                *output_file << time_str + "debug: " + str_with_no_033m;
            if (use_temp_files)
                for (auto& i : temp_output_files_set)
                    *i << time_str + "debug: " + str_with_no_033m;
        }
    }

    logstream::logstream() {
        use_stdout = true;
        use_file = false;
        use_temp_files = false;
        use_add_time = false;

        output_console = &std::cout;
        output_file = nullptr;
        log_func = std::bind(&logstream::log_debug, this, std::placeholders::_1);
    }

    void logstream::change_output_console(std::ostream& c) {
        output_console = &c;
    }

    void logstream::change_output_file(std::ofstream& f) {
        output_file = &f;
    }

    void logstream::add_temp_output_file(std::ofstream& f) {
        temp_output_files_set.insert(&f);
    }

    void logstream::del_all_temp_output_file() {
        temp_output_files_set.clear();
        temp_output_files_set = decltype(temp_output_files_set)();  // free the capacity
    }

    logstream& logstream::operator<<(stage st) {
        switch (st) {
        case error:
            log_func = std::bind(&logstream::log_error, this, std::placeholders::_1);
            break;
        case warning:
            log_func = std::bind(&logstream::log_warning, this, std::placeholders::_1);
            break;
        case std:
            log_func = std::bind(&logstream::log_std, this, std::placeholders::_1);
            break;
        case info:
            log_func = std::bind(&logstream::log_info, this, std::placeholders::_1);
            break;
        case debug:
            log_func = std::bind(&logstream::log_debug, this, std::placeholders::_1);
            break;
        }
        return *this;
    }

    logstream& logstream::operator<<(operat op) {
        switch (op) {
        case endl:
            log_func(ss.str());
            ss.str(std::string());
            if (use_stdout || last_stage == error)
                *output_console << std::endl;
            if (use_file)
                *output_file << std::endl;
            if (use_temp_files)
                for (auto& i : temp_output_files_set)
                    *i << std::endl;
            break;
        case flush:
            log_func(ss.str());
            ss.str(std::string());
            if (use_stdout || last_stage == error)  // error will always output to stdout
                *output_console << std::flush;
            if (use_file)
                *output_file << std::flush;
            if (use_temp_files)
                for (auto& i : temp_output_files_set)
                    *i << std::flush;
            break;
        }
        return *this;
    }

    logstream& logstream::operator<<(target t) {
        switch (t) {
        case stdout_on: use_stdout = true; break;
        case stdout_off: use_stdout = false; break;
        case file_on: use_file = true; break;
        case file_off: use_file = false; break;
        case temp_files_on: use_temp_files = true; break;
        case temp_files_off: use_temp_files = false; break;
        }
        return *this;
    }

    logstream& logstream::operator<<(timeadd ta) {
        switch (ta) {
        case add_time: use_add_time = true; break;
        case no_time: use_add_time = false; break;
        }
        return *this;
    }

    logstream log;
}