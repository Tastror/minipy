#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>
#include <functional>

#include "common.h"
#include "color.h"
#include "log.h"

namespace stdlog {
    stage log_stage = stage::debug;
    bool add_time = false;

    LogType::LogType() {
        use_file = false;
        use_stdin = true;
        log_func = std::bind(&LogType::debug, this, std::placeholders::_1);
    }

    void LogType::change_output_file(std::ofstream& f) {
        of = &f;
    }

    void LogType::add_temp_output_file(std::ofstream& f) {
        tmp.insert(&f);
    }

    void LogType::del_all_temp_output_file() {
        tmp.clear();
        tmp = decltype(tmp)();  // free the capacity
    }


    LogType& LogType::operator<<(stdlog::operat op) {
        switch (op) {
        case stdlog::endl:
            log_func(ss.str());
            ss.str(std::string());
            // error will always output on stdin !!!
            if (use_stdin || last_stage == stdlog::error)
                std::cout << std::endl;
            if (use_file) {
                *of << std::endl;
                for (auto& i : tmp)
                    *i << std::endl;
            }
            break;
        case stdlog::flush:
            log_func(ss.str());
            ss.str(std::string());
            // error will always output on stdin !!!
            if (use_stdin || last_stage == stdlog::error)
                std::cout << std::flush;
            if (use_file) {
                *of << std::flush;
                for (auto& i : tmp)
                    *i << std::flush;
            }
            break;
        case stdlog::to_stdout:
            use_stdin = true;
            use_file = false;
            break;
        case stdlog::to_file:
            use_stdin = false;
            use_file = true;
            break;
        case stdlog::to_stdout_and_file:
            use_stdin = use_file = true;
            break;
        default:
            break;
        }
        return *this;
    }

    LogType& LogType::operator<<(stdlog::stage st) {
        switch (st) {
        case stdlog::error:
            log_func = std::bind(&LogType::error, this, std::placeholders::_1);
            break;
        case stdlog::warning:
            log_func = std::bind(&LogType::warning, this, std::placeholders::_1);
            break;
        case stdlog::std:
            log_func = std::bind(&LogType::std, this, std::placeholders::_1);
            break;
        case stdlog::info:
            log_func = std::bind(&LogType::info, this, std::placeholders::_1);
            break;
        case stdlog::debug:
            log_func = std::bind(&LogType::debug, this, std::placeholders::_1);
            break;
        default:
            log_func = std::bind(&LogType::std, this, std::placeholders::_1);
            break;
        }
        return *this;
    }

    void LogType::debug(const std::string& str) {
        last_stage = stdlog::debug;
        if (unsigned(stdlog::log_stage) >= unsigned(stdlog::stage::debug)) {
            std::string time_str = stdlog::add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdin)
                std::cout << GREEN << time_str << PURPLE << "debug: " + str << RESET;
            if (use_file) {
                *of << time_str + "debug: " + str;
                for (auto& i : tmp)
                    *i << time_str + "debug: " + str;
            }
        }
    }

    void LogType::info(const std::string& str) {
        last_stage = stdlog::info;
        if (unsigned(stdlog::log_stage) >= unsigned(stdlog::stage::info)) {
            std::string time_str = stdlog::add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdin)
                std::cout << GREEN << time_str << CYAN << "info: " + str << RESET;
            if (use_file) {
                *of << time_str + "info: " + str;
                for (auto& i : tmp)
                    *i << time_str + "info: " + str;
            }
        }
    }

    void LogType::std(const std::string& str) {
        last_stage = stdlog::std;
        if (unsigned(stdlog::log_stage) >= unsigned(stdlog::stage::std)) {
            std::string time_str = stdlog::add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdin)
                std::cout << GREEN << time_str << RESET << str << RESET;
            if (use_file) {
                *of << time_str + str;
                for (auto& i : tmp)
                    *i << time_str + str;
            }
        }
    }

    void LogType::warning(const std::string& str) {
        last_stage = stdlog::warning;
        if (unsigned(stdlog::log_stage) >= unsigned(stdlog::stage::warning)) {
            std::string time_str = stdlog::add_time ? "[" + timing::local_time() + "] " : "";
            if (use_stdin)
                std::cout << GREEN << time_str << YELLOW << "warning: " + str << RESET;
            if (use_file) {
                *of << time_str + "warning: " + str;
                for (auto& i : tmp)
                    *i << time_str + "warning: " + str;
            }
        }
    }

    void LogType::error(const std::string& str) {
        last_stage = stdlog::error;
        if (unsigned(stdlog::log_stage) >= unsigned(stdlog::stage::error)) {
            std::string time_str = stdlog::add_time ? "[" + timing::local_time() + "] " : "";
            // error will always output on stdin !!!
            std::cout << GREEN << time_str << RED << "error: " + str << RESET;
            if (use_file) {
                *of << time_str + "error: " + str;
                for (auto& i : tmp)
                    *i << time_str + "error: " + str;
            }
        }
    }

    LogType log;
}