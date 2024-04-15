
CXX = g++
CXXFLAGS = -Wall -std=c++11

all: parking

parking: parking.o
	$(CXX) $(CXXFLAGS) -o parking $^

parking.o: parking.cc

clean:
	rm -f parking *.o
