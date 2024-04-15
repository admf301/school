
CXX = g++
CXXFLAGS = -Wall -std=c++11

all: binarytree

binarytree: binarytree.o
	$(CXX) $(CXXFLAGS) -o binarytree $^

binarytree.o: binarytree.cc btree.h node.h

clean:
	rm -f binarytree *.o
