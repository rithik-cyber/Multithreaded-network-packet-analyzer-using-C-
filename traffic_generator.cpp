#include "traffic_generator.h"
#include <iostream>
#include <thread>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "utils.h"

void generateTraffic(int protocol, const std::string& destination, int port, int duration) {
    int sock = socket(AF_INET, (protocol == SOCK_STREAM) ? SOCK_STREAM : SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "Error creating socket.\n";
        return;
    }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, destination.c_str(), &server.sin_addr);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        handleError("Connection failed.");
    }

    logMessage("Generating traffic to " + destination + " on port " + std::to_string(port));
    const char* payload = "Test Traffic Packet";
    for (int i = 0; i < duration; ++i) {
        send(sock, payload, strlen(payload), 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    close(sock);
    logMessage("Traffic generation complete.");
}
