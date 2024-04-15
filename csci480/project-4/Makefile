CXX = g++
CXXFLAGS = -Wall -std=c++20 -pthread

z1913104_project4: z1913104_project4.o
	$(CXX) $(CXXFLAGS) -o z1913104_project4 $^

z1913104_project.o: z1913104_project4.cc

clean:
	rm -f z1913104_project4 *.o
