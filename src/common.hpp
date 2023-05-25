#pragma once

#include <chrono>
#include <thread>
#include <string>
#include <iomanip>

namespace timing {

    std::string local_time() {
        std::stringstream str_stream;
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        str_stream << std::put_time(&tm, "%c");
        return str_stream.str();
    }

    std::string local_time_for_file() {
        std::stringstream str_stream;
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        str_stream << std::put_time(&tm, "%Y-%m-%d-%H-%M-%S");
        return str_stream.str();
    }

    // return std::chrono::steady_clock::time_point
    // use auto to get it
    auto now() {
        return std::chrono::steady_clock::now();
    }
}