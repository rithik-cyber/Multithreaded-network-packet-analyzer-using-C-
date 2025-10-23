#include "packet_capture.h"
#include "metrics.h"  // Include the metrics header
#include <iostream>
#include <vector>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void inspectPacket(const u_char* packet, struct pcap_pkthdr* header) {
    const struct ip* ipHeader = (struct ip*)(packet + 14); // Skip Ethernet header
    std::string srcIP = inet_ntoa(ipHeader->ip_src);
    std::string dstIP = inet_ntoa(ipHeader->ip_dst);

    std::cout << "Packet captured: " << header->len << " bytes\n";
    std::cout << "Source IP: " << srcIP << ", Destination IP: " << dstIP << "\n";

    if (ipHeader->ip_p == IPPROTO_TCP) {
        const struct tcphdr* tcpHeader = (struct tcphdr*)(packet + 14 + (ipHeader->ip_hl * 4));
        std::cout << "TCP Packet - Source Port: " << ntohs(tcpHeader->th_sport)
                  << ", Destination Port: " << ntohs(tcpHeader->th_dport) << "\n";
    } else if (ipHeader->ip_p == IPPROTO_UDP) {
        const struct udphdr* udpHeader = (struct udphdr*)(packet + 14 + (ipHeader->ip_hl * 4));
        std::cout << "UDP Packet - Source Port: " << ntohs(udpHeader->uh_sport)
                  << ", Destination Port: " << ntohs(udpHeader->uh_dport) << "\n";
    }
    std::cout << "-----------------------------------------\n";
}

void captureTraffic(const std::string& interface, int duration) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(interface.c_str(), BUFSIZ, 1, 1000, errbuf);
    if (!handle) {
        std::cerr << "Error opening device: " << errbuf << "\n";
        return;
    }

    std::cout << "Capturing packets on interface " << interface << "...\n";
    struct pcap_pkthdr* header;
    const u_char* packet;
    std::vector<int> packetSizes;  // Vector to store packet sizes

    for (int i = 0; i < duration; ++i) {
        if (pcap_next_ex(handle, &header, &packet) > 0) {
            inspectPacket(packet, header);  // Parse and display packet details
            packetSizes.push_back(header->len);  // Store the size of the captured packet
        }
    }

    pcap_close(handle);

    // Calculate and display metrics
    calculateMetrics(packetSizes, duration);
}
