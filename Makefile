CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/traffic_generator.cpp src/packet_capture.cpp src/traffic_analyzer.cpp src/utils.cpp 
OBJ = $(SRC:.cpp=.o)
TARGET = network_analyzer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lpcap

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
