# Makefile

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -lglfw -lGL -lGLEW -lSOIL -lassimp

# Target executable name
TARGET = scene

# Source files
SRC = main.cpp

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS)

# Target to run the program
run: all
	./$(TARGET)

# Clean up
clean:
	rm -f $(TARGET)

.PHONY: all run clean
