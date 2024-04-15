
#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iomanip>

using namespace std;

class shape
{

private:

	string color;

public:
	//function and de/constructor prototypes
	shape(const string& color);
	virtual const void print();
	virtual double get_area() = 0;
	virtual ~shape();
};

#endif
