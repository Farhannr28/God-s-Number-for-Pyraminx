CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = src
BUILD_DIR = build

# List all .cpp files in the source directory
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Create a list of corresponding object files in the build directory
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main target
main.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target
clean:
	rm -rf $(BUILD_DIR) main.exe

.PHONY: clean