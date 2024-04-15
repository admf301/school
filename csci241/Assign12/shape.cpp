
#include "shape.h"
#include <iostream>

//constructor
shape::shape(const string& color)
{
	this->color = color;
}

//print
const void shape::print()
{
	cout << color;
}

//destructor
shape::~shape()
{

}
