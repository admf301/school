
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class circle:public shape
{

private:

	int radius;

public:

	//function prototypes
	circle(const string&, int);
	const void print();
	double get_area();
	~circle();
};

#endif
