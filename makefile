CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = driver_database

SRCS = main.cpp Driver.cpp HashTable.cpp LinkedList.cpp DriverDatabase.cpp
OBJS = $(SRCS:.cpp = .o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp DriverDatabase.HashTable
	$(CXX) $(CXXFLAGS) -c main.cpp

Driver.o: Driver.cpp Driver.h 
	$(CXX) $(CXXFLAGS) -c Driver.cpp

HashTable.o: HashTable.cpp HashTable.h Driver.h 
	$(CXX) $(CXXFLAGS) -c HashTable.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Driver.h 
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

DriverDatabase.o: DriverDatabase.cpp DriverDatabase.h Driver.h HashTable.h LinkedList.h 
	$(CXX) $(CXXFLAGS) -c DriverDatabase.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)