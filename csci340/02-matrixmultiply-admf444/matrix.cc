
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include "matrix.h"

/**
* Default matrix constructor
*
* Creates a 2D vector of size (rows x cols) filled with zeros
*
* @param rows - number of rows
* @param cols - number of columns
******************************************************************************/
matrix::matrix(unsigned int rows, unsigned int cols)
{
	mat = std::vector<std::vector<int>> (rows, std::vector<int>(cols, 0));
}

/**
* Matrix resize function
*
* Resizes the 2D vector (mat) of size (rows x cols) filled with zeros
*
* @param rows - number of rows
* @param cols - number of columns
******************************************************************************/
void matrix::resize(unsigned int rows, unsigned int cols)
{
	mat = std::vector<std::vector<int>> (rows, std::vector<int>(cols, 0));
}

/**
* Overloaded (*) operator
*
* Overloads (*) operator to perform matrix multiplication C(i,j) = A(i,k) * B(k,j)
* by using 2 matrix objects as operands
*
* @param rhs - right hand side operand
* @return - the resulting matrix after multiplying the left and right operands
******************************************************************************/
matrix matrix::operator*(const matrix &rhs) const
{
	int rrow = this->getRows();
	int rcol = this->getCols();

	matrix result(rrow, rcol);

	result.resize(rrow, rhs.getCols());
	assert((unsigned int)rrow == rhs.getCols());

	for(int i = 0; i < rrow; i++)
	{
		for(unsigned int j = 0; j < rhs.getCols(); j++)
		{
			for(int k = 0; k < rcol; k++)
			{
				result.at(i,j) += this->at(i,k) * rhs.at(k,j);
			}
		}
	}

	return result;
}

/**
* Loads 2D vector with values from a file
*
* Extracts integers from istream, then push the integer onto temp vector
* then push temp vector onto mat vector to create a 2D vector
*
* @param is - input file stream
******************************************************************************/
void matrix::load(std::istream &is)
{
	unsigned int rows, cols;
	is >> rows;
	is >> cols;

	for(unsigned int i = 0; i < rows; i++)
	{
		std::vector<int> temp;
		for(unsigned int j = 0; j < cols; j++)
		{
			int val;
			is >> val;
			temp.push_back(val);
		}

		mat.push_back(temp);
	}
}

/**
* Print formatted output
*
* Prints a formatted box containing each matrix and matrix size description
*
* @param colWidth - set coloumn width to display
*******************************************************************************/
void matrix::print(int colWidth) const
{
	unsigned int rwidth = colWidth + 1;
	unsigned int pdash = (rwidth + 1) * mat[0].size();

	std::cout << mat.size() << " x " << mat[0].size() << std::endl;

	for(unsigned int p = 0; p <= pdash; p++)
	{
		std::cout << '-';
	}

	std::cout << std::endl;

	for(unsigned int i = 0; i < mat.size(); i++)
	{

		for(unsigned int j = 0; j < mat[i].size(); j++)
		{
			std::cout << "|" << std::setw(colWidth) << mat[i][j] << " ";
		}

		std::cout << "|" << std::endl;
	}

	for(unsigned int q = 0; q <= pdash; q++)
	{
		std::cout << '-';
	}

	std::cout << std::endl;
}
