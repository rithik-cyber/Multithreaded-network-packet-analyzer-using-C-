#ifndef TRAFFIC_GENERATOR_H
#define TRAFFIC_GENERATOR_H

#include <string>

void generateTraffic(int protocol, const std::string& destination, int port, int duration);

#endif
