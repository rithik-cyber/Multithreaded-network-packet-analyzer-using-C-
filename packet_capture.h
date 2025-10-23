#ifndef PACKET_CAPTURE_H
#define PACKET_CAPTURE_H

#include <string>

void captureTraffic(const std::string& interface, int duration);

#endif
