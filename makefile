# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Executable name
TARGET = animation_engine

# Source files
SRCS = main.cpp functions.cpp Circle.cpp Renderer.cpp

# Object files (automatically derived from SRCS)
OBJS = $(SRCS:.cpp=.o)

# Header files (for dependency tracking)
DEPS = functions.h Layer.h Circle.h Renderer.h

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
