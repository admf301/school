
FLAGS = -Wall -Werror -std=c++11

assign12: assign12.o shape.o circle.o rectangle.o triangle.o
	g++ $(FLAGS) -o assign12 assign12.o shape.o circle.o rectangle.o triangle.o

assign12.o: assign12.cpp shape.h circle.h rectangle.h triangle.h
	g++ $(FLAGS) -c assign12.cpp

shape.o: shape.cpp shape.h
	g++ $(FLAGS) -c shape.cpp

circle.o: circle.cpp circle.h
	g++ $(FLAGS) -c circle.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ $(FLAGS) -c rectangle.cpp

triangle.o: triangle.cpp triangle.h
	g++ $(FLAGS) -c triangle.cpp

circle.h: shape.h

rectangle.h: shape.h

triangle.h: shape.h

clean:
	-rm *.o assign12
