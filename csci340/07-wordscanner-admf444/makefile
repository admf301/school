
CXX = g++
CXXFLAGS = -Wall -std=c++11

all: wordscanner

wordscanner: wordscanner.o
	$(CXX) $(CXXFLAGS) -o wordscanner $^

wordscanner.o: wordscanner.cc

clean:
	rm -f wordscanner *.o
