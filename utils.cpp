#include "utils.h"
#include <ctime>
#include <iomanip>
#include <sstream>

void logMessage(const std::string& message) {
    std::cout << "[" << getCurrentTimestamp() << "] " << message << std::endl;
}

void handleError(const std::string& errorMessage) {
    std::cerr << "[" << getCurrentTimestamp() << "] ERROR: " << errorMessage << std::endl;
    // Optionally terminate the program
    exit(EXIT_FAILURE);
}

std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
