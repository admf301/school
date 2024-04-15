
#include "rectangle.h"
#include <iostream>
#include <iomanip>
using namespace std;

//constructor
rectangle::rectangle(const string& color, int height, int width):shape(color)
{
	this->height = height;
	this->width = width;
}

//print
const void rectangle::print()
{
	cout << fixed << setprecision(0);
	shape::print();
	cout << " rectangle, height " << height << ", width " << width << ", area " << get_area() << endl;
}

//returns area of a rectangle
double rectangle::get_area()
{
	return (double)height*(double)width;
}

//destructor
rectangle::~rectangle()
{

}
