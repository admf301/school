
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle:public shape
{

private:

	int height;
	int width;

public:

	//function prototypes...
	rectangle(const string&, int, int);
	const void print();
	double get_area();
	~rectangle();
};

#endif
