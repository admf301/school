
#include "triangle.h"
#include <iostream>
#include <iomanip>
using namespace std;

//the constructor
triangle::triangle(const string& color, int height, int base):shape(color)
{
	this->height = height;
	this->base = base;
}

//the print
const void triangle::print()
{
	cout << fixed << setprecision(0);
	shape::print();
	cout << " triangle, height " << height << ", base " << base << ", area " << get_area() << endl;
}

//returns the area of a triangle
double triangle::get_area()
{
	return ((double)height*(double)base)/2.0;
}

//the destructor
triangle::~triangle()
{

}
