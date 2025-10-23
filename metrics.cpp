#include "metrics.h"
#include <iostream>
#include <numeric>

void calculateMetrics(const std::vector<int>& packetSizes, int duration) {
    int totalBytes = std::accumulate(packetSizes.begin(), packetSizes.end(), 0);
    double throughput = static_cast<double>(totalBytes) / duration; // Bytes per second

    std::cout << "----- Network Performance Metrics -----\n";
    std::cout << "Total Packets: " << packetSizes.size() << "\n";
    std::cout << "Total Data: " << totalBytes / 1024.0 << " KB\n";
    std::cout << "Throughput: " << throughput / 1024.0 << " KB/s\n";
    std::cout << "---------------------------------------\n";
}
