#pragma once

#include <chrono>
#include <thread>
#include <string>
#include <iomanip>

enum class none {};

namespace timing {

    std::string local_time();

    std::string local_time_for_file();

    // return std::chrono::steady_clock::time_point
    // use auto to get it
    auto now();
}