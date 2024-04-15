
#include <iostream>
#include "matrix.h"

using namespace std;

//default constructor
matrix::matrix()
{
	matrixArray[0][0] = 1;
	matrixArray[0][1] = 0;
	matrixArray[1][0] = 0;
	matrixArray[1][1] = 1;
}

//overload stream insertion operator to print correct output
//reference to ostream object representing the left operand of the stream insertion
//reference to constant matrix object
//@return ostream object to cascade the operator
ostream& operator<<(ostream& lhs, const matrix& rhs)
{
	lhs << "[[" << rhs.matrixArray[0][0] << ", " << rhs.matrixArray[0][1] << "], ["
	<< rhs.matrixArray[1][0] << ", " << rhs.matrixArray[1][1] << "]]";

	return lhs; //cascade operator
}

//initialization constructor
//@param optMatrix is a 2 dimensional array of ints
matrix::matrix(int optMatrix[2][2])
{
	//set the matrixArray by looping through the rows and columns
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 2; c++)
		{
			matrixArray[r][c] = optMatrix[r][c];
		}
	}
}

//calculates the determinant (ad-bc) of a 2 by 2 matrix
//@returns an integer representing the determinant of the matrix
int matrix::determinant() const
{
	return (matrixArray[0][0] * matrixArray[1][1]) - (matrixArray[1][0] * matrixArray[0][1]);
}

//overload (+) operator to calculate the sum of 2 matrices of size 2 by 2
//@param const matrix& rhs is a reference to a constant matrix object representing the right operand
//left operand is represented by this
//@returns a matrix object which is the sum of the left and right operands
matrix matrix::operator+(const matrix& rhs) const
{
	//initialize new matrix object with the left operand
	matrix sum = *this;

	//loop through rows and columns
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 2; c++)
		{
			//calculate and assign the sum of element matrices to the sum object
			sum.matrixArray[r][c] = this->matrixArray[r][c] + rhs.matrixArray[r][c];
		}
	}

	return sum;
}

//overload (*) operator to calculate matrix scalar multiplication (right side)
//@param int rhs represents the right operand
//left operand represented by this
//@returns a matrix object which is the result of multiplying the elements of the matrix by the scalar
matrix matrix::operator*(int rhs) const
{
	//initialize new matrix object with left operand
	matrix result = *this;

	//loop through rows and columns
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 2; c++)
		{
			//calculate and assign the multiplication of an element by the int to the result object
			result.matrixArray[r][c] *= rhs;
		}
	}

	return result;
}

//overload (*) operator to calculate matrix scalar multiplication (left side)
//@param int lhs represents the left operand
//@param const matrix& rhs is a reference to a consant matrix object representing the right operand
//@returns a matrix object which is the result of multiplying the elements of the matrix by the scalar
matrix operator*(int lhs, const matrix& rhs)
{
	//initialize new matrix object
	matrix result;

	//loop through rows and columns
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 2; c++)
		{
			//calculate and assign the multiplication of an element by the int to the result object
			result.matrixArray[r][c] = rhs.matrixArray[r][c] * lhs;
		}
	}

	return result;
}

//overload (*) operator to calculate product of 2 matrices of size 2 by 2
//@param const matrix& rhs is a reference to a constant matrix object representing the right operand
//left operand is represented by this
//@returns a matrix object which is the product of the left and right operands
matrix matrix::operator*(const matrix& rhs) const
{
	//initialize new matrix object
	matrix result;

	//calculate the product of each element and assign to result object
	result.matrixArray[0][0] = (this-> matrixArray[0][0] * rhs.matrixArray[0][0]) + (this-> matrixArray[0][1] * rhs.matrixArray[1][0]);
	result.matrixArray[0][1] = (this-> matrixArray[0][0] * rhs.matrixArray[0][1]) + (this-> matrixArray[0][1] * rhs.matrixArray[1][1]);
	result.matrixArray[1][0] = (this-> matrixArray[1][0] * rhs.matrixArray[0][0]) + (this-> matrixArray[1][1] * rhs.matrixArray[1][0]);
	result.matrixArray[1][1] = (this-> matrixArray[1][0] * rhs.matrixArray[0][1]) + (this-> matrixArray[1][1] * rhs.matrixArray[1][1]);

	return result;
}

//overload (==) operator to determine if all elements of left operand are equal to all elements of right operand
//@param const matrix& rhs is a reference to a constant matrix object representing the right operand
//left operand is represented by this
//@returns false if all elements are not equal
//@returns true if all elements are equal
bool matrix::operator==(const matrix& rhs) const
{
	//loop through rows and columns
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 2; c++)
		{
			//checking for equality
			if(this-> matrixArray[r][c] != rhs.matrixArray[r][c])
			{
				return false;
			}
		}
	}

	return true;
}

//overload (!=) operator to determine if all elements of left operand are not equal to all elements of right operand
//@param const matrix& rhs is a reference to a constant matrix object representing the right operand
//left operand represented by this
//@returns false if elements are equal
//@returns true if elements are not equal
bool matrix::operator!=(const matrix& rhs) const
{
	//loop through rows and columns
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 2; c++)
		{
			//checking for equality
			if(this-> matrixArray[r][c] == rhs.matrixArray[r][c])
			{
				return false;
			}
		}
	}

	return true;
}
