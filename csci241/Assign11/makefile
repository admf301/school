
# Compiler variables
CXXFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file

assign11: assign11.o
	g++ $(CXXFLAGS) -o assign11 assign11.o

# Rules to compile source code files to object code
assign11.o: assign11.cpp bstree.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign11 *.o
