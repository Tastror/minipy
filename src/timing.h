#pragma once

#include <chrono>
#include <thread>
#include <string>
#include <iomanip>

namespace timing {
    std::string local_time();
    std::string local_time_for_file();
}