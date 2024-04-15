
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class triangle:public shape
{

private:

	int height;
	int base;

public:

	//prototype functionssss
	triangle(const string&, int, int);
	const void print();
	double get_area();
	~triangle();
};

#endif
