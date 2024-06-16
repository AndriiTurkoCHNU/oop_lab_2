#include "Constants.h"


string currentLocalDateTime() {
    auto now = std::time(nullptr);
    auto localTime = std::localtime(&now);
    std::ostringstream ss;
    ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}