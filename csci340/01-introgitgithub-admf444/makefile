CXX = g++
CXXFLAGS = -Wall -std=c++11

introduction: introduction.o
		$(CXX) $(CXXFLAGS) -o introduction $^
introduction.o: introduction.cc

clean:
	rm -f introduction *.o
