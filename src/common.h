#pragma once

#include <chrono>
#include <thread>
#include <string>
#include <iomanip>

enum class none {};

namespace timing {
    std::string local_time();
    std::string local_time_for_file();
}