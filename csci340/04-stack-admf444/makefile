
CXX = g++
CXXFLAGS = -Wall -std=c++11

all: stack

stack: main.o rational.o
	$(CXX) $(CXXFLAGS) -o stack $^

main.o: main.cc rational.h stack.h

rational.o: rational.cc rational.h

clean:
	rm -f stack *.o
