# Compiler and flags
CC = g++
CFLAGS = -Wall -O2 -std=c++11 

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Executable name
EXECUTABLE = RT_Sim

# Main target
all: $(EXECUTABLE)

# Build the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean rule to remove build artifacts
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

.PHONY: all clean
