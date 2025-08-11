# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Output binary name
TARGET = main

# Source files
SRCS = main.cpp LinkedList.cpp Person.cpp Student.cpp Faculty.cpp

# Object files (replaces .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean object and binary files
clean:
	rm -f $(OBJS) $(TARGET)