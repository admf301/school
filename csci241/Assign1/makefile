
# Compiler variablesa
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
all: bubble_sort insertion_sort selection_sort testing

bubble_sort: bubble_sort.o
	$(CXX) $(CXXFLAGS) -o bubble_sort bubble_sort.o

insertion_sort: insertion_sort.o
	$(CXX) $(CXXFLAGS) -o insertion_sort insertion_sort.o

selection_sort: selection_sort.o
	$(CXX) $(CXXFLAGS) -o selection_sort selection_sort.o

testing: testing.o
	$(CXX) $(CXXFLAGS) -o testing testing.o

# Rules to compile source code files to object code
bubble_sort.o: bubble_sort.cpp
insertion_sort.o: insertion_sort.cpp
selection_sort.o: selection_sort.cpp
testing: testing.cpp

# Pseudo-target to remove object code and executable files
clean:
	rm -f *.o bubble_sort insertion_sort selection_sort testing
