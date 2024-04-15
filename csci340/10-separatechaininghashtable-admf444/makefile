
CXX = g++
CXXFLAGS = -Wall -std=c++11

all: hash

hash: hashmain.o htable.o
	$(CXX) $(CXXFLAGS) -o hash $^

hashmain.o: hashmain.cc hashmain.h entry.h

htable.o: htable.cc htable.h entry.h

clean:
	rm -f hash *.o
