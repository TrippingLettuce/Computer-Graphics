# Makefile

# Variables
CXX = g++
CXXFLAGS = -lglut -lGLU -lGL
TARGET = scene
SRC = scene.cpp

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(SRC)
	$(CXX) $^ -o $@ $(CXXFLAGS)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean the build
clean:
	rm -f $(TARGET)
