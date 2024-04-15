
CXX = g++
CXXFLAGS = -Wall -std=c++11

all: simplegraph

simplegraph: simplegraph.o graph.o
	$(CXX) $(CXXFLAGS) -o simplegraph $^

simplegraph.o: simplegraph.cc graph.h

graph.o: graph.cc graph.h

clean:
	rm -f simplegraph *.o
