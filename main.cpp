#include "traffic_generator.h"
#include "packet_capture.h"
#include "traffic_analyzer.h"
#include <iostream>
#include <thread>
#include <sys/socket.h> 
#include "metrics.cpp"

void showMenu() {
    std::cout << "1. Start Traffic Generation\n";
    std::cout << "2. Capture Traffic\n";
    std::cout << "3. Analyze Metrics\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    std::vector<int> packetSizes;
    while (true) {
        showMenu();
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Enter destination IP: ";
            std::string destIP;
            std::cin >> destIP;
            generateTraffic(SOCK_STREAM, destIP, 8080, 10);
        } else if (choice == 2) {
            captureTraffic("en0", 10);
        } else if (choice == 3) {
            // Assume metrics are stored globally
            calculateMetrics(packetSizes, 10);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}