#include <chrono>
#include <thread>
#include <string>
#include <iomanip>

#include "common.h"

namespace timing {

    int64_t now_ms() {
        auto now = std::chrono::system_clock::now();
        auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);
        auto fraction = now - seconds;
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);
        return milliseconds.count();
    }

    std::string local_time() {
        std::stringstream str_stream;
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        str_stream << std::put_time(&tm, "%Y/%m/%d %H:%M:%S") << "." << std::setfill('0') << std::setw(3) << now_ms();
        return str_stream.str();
    }

    std::string local_time_for_file() {
        std::stringstream str_stream;
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        str_stream << std::put_time(&tm, "%Y-%m-%d-%H-%M-%S") << "-" << std::setfill('0') << std::setw(3) << now_ms();;
        return str_stream.str();
    }
}