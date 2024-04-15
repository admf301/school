
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//create shape objects
	vector<shape*> shape_v;
	shape_v.push_back(new circle("green", 10));
	shape_v.push_back(new rectangle("red", 8, 6));
	shape_v.push_back(new triangle("yellow", 8, 4));
	shape_v.push_back(new triangle("black", 4, 10));
	shape_v.push_back(new circle("orange", 5));
	shape_v.push_back(new rectangle("blue", 3, 7));

	//print all shapes
	cout << "\nPrinting all shapes...\n\n";
	vector<shape*>::iterator shapeit;

	for(shapeit = shape_v.begin(); shapeit < shape_v.end(); shapeit++)
	{
		(*shapeit)->print();
	}

	//print only circles
	cout << "\nPrinting only circles...\n\n";

	for(shapeit = shape_v.begin(); shapeit < shape_v.end(); shapeit++)
	{
		if(typeid(*(*shapeit)) == typeid(circle))
		{
			(*shapeit)->print();
		}
	}

	//delete memory allocated to shape objects
	for(shapeit = shape_v.begin(); shapeit < shape_v.end(); shapeit++)
	{
		delete(*shapeit);
	}

	return 0; //byeeeee
}
