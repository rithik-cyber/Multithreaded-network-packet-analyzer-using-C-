# **Network Analyzer**

## **Overview**
The **Network Analyzer** is a multi-threaded network traffic simulator and packet analyzer built in C++. It combines networking, multi-threading, and performance metrics to provide real-time insights into network behavior. The program can:
- Generate configurable network traffic (TCP/UDP).
- Capture and inspect network packets in real time.
- Analyze network performance with metrics like throughput and packet sizes.

This project demonstrates expertise in C++ networking, system programming, and performance analysis.

---

## **Features**
- **Traffic Generation**:
  - Sends customizable TCP or UDP traffic to a specified destination.
  - Supports valid HTTP requests to interact with web servers.

- **Packet Capture**:
  - Captures packets on a specified network interface using `libpcap`.
  - Parses packet headers to display details (IP, port, protocol, etc.).

- **Performance Metrics**:
  - Calculates throughput, total packets, and data transfer.
  - Displays real-time insights into network performance.

- **Multi-threaded Design**:
  - Uses separate threads for traffic generation, packet capture, and analysis.

---

## **Installation**

### **Requirements**
1. **Operating System**:
   - Linux or macOS (Tested on macOS).
2. **Dependencies**:
   - `libpcap` (for packet capture).
     - Install on Linux:
       ```bash
       sudo apt-get install libpcap-dev
       ```
     - Install on macOS:
       ```bash
       brew install libpcap
       ```
3. **Compiler**:
   - GCC or Clang with C++17 support.

### **Build Instructions**
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd network-analyzer
   ```
2. Build the project using `make`:
   ```bash
   make
   ```

3. Clean the build:
   ```bash
   make clean
   ```

---

## **Usage**

### **Run the Program**
1. Start a local HTTP server (optional, for testing traffic generation):
   ```bash
   python3 -m http.server 8080
   ```

2. Execute the program with `sudo` (required for packet capture):
   ```bash
   sudo ./network_analyzer <interface> <destination_ip>
   ```
   - **`<interface>`**: Network interface for capturing packets (e.g., `en0`).
   - **`<destination_ip>`**: Target IP for traffic generation (e.g., `127.0.0.1`).

### **Example**
```bash
sudo ./network_analyzer en0 127.0.0.1
```

### **Expected Output**
1. Traffic Generation:
   - Sends HTTP requests to the specified IP and port.
2. Packet Capture:
   - Logs details of captured packets in real time.
3. Performance Metrics:
   - Displays total packets, data size, and throughput.

---

## **Features in Detail**

### **Traffic Generation**
- Generates TCP or UDP traffic.
- Sends valid HTTP requests when targeting a web server.

### **Packet Capture**
- Uses `libpcap` to capture packets on the specified network interface.
- Parses packet headers to extract:
  - Protocol (TCP/UDP).
  - Source and destination IP.
  - Port numbers.
  - Packet size.

### **Performance Metrics**
- Calculates:
  - Total packets sent/received.
  - Total data transferred.
  - Throughput (KB/s).

---

## **Project Structure**
```plaintext
network-analyzer/
├── src/
│   ├── main.cpp                # Main entry point
│   ├── traffic_generator.cpp   # Traffic generation logic
│   ├── packet_capture.cpp      # Packet capture and parsing
│   ├── traffic_analyzer.cpp    # Analysis logic
│   ├── metrics.cpp             # Performance metrics
│   ├── utils.cpp               # Logging and helper functions
├── include/
│   ├── traffic_generator.h     # Traffic generation header
│   ├── packet_capture.h        # Packet capture header
│   ├── traffic_analyzer.h      # Analysis header
│   ├── metrics.h               # Metrics header
│   ├── utils.h                 # Utilities header
├── Makefile                    # Build automation
├── README.md                   # Documentation
```

---

## **Future Enhancements**
- Add support for encrypted traffic (SSL/TLS).
- Visualize traffic metrics with a real-time dashboard.
- Extend packet analysis to support ICMP and ARP.
- Include logging to a file for long-term analysis.

---


## **Contact**
For questions or contributions, feel free to reach out:
- **Author**: Suyash Salvi
- **Email**: ssalvi2898@gmail.com

---

Let me know if you want help customizing this further!
