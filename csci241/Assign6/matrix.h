
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class matrix
{

//friend function prototypes for overloading (<<) and (*) operators
friend ostream& operator<<(ostream&, const matrix&);  //overload stream insertion operator
friend matrix operator*(int, const matrix&);	      //overload (*) operator

private:
	int matrixArray[2][2];

public:
	matrix operator+(const matrix& rhs) const;  //overload (+) operator
	matrix operator*(int) const;		    //overload (*) operator
	matrix operator*(const matrix&) const;      //overload (*) operator
	bool operator==(const matrix&) const;       //overload (==) operator
	bool operator!=(const matrix&) const;       //overload (!=) operator

	//constructors
	matrix();
	matrix(int[2][2]);

	//function prototype
	int determinant() const;
};

#endif
