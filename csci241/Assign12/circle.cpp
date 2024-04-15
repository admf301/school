
#include "circle.h"
#include <iostream>
#include <iomanip>
#define M_PI 3.14159265358979323846
using namespace std;

//constructor
circle::circle(const string& color, int radius):shape(color)
{
	this->radius = radius;
}

//print
const void circle::print()
{
	cout << fixed << setprecision(3);
	shape::print();
	cout << " circle, radius " << radius <<  ", area " << get_area() << endl;
}

//returns area of a circle
double circle::get_area()
{
	return (double)M_PI*radius*radius;
}

//deeestructorrrr
circle::~circle()
{

}
