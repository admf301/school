
#include <iostream>
#include <iomanip>
#include <cstring>
#include "book.h"

using namespace std;

//Constructor
book::book(const char* set_isbn, const char* set_title, double set_price, int set_stock)
{
	strcpy(isbn, set_isbn);
	strcpy(title, set_title);
	price = set_price;
	stock = set_stock;
}

//get_isbn() returns the isbn of the book object
const char* book::get_isbn() const
{
	return isbn;
}

//get_price() returns the price of the book object
double book::get_price() const
{
	return price;
}

//fufill_orders(int) returns the amount of books sold from the stock if there are enough books available
//@param int q represents the number of that book that was ordered
//returns number of that book sucessfully sold
int book::fulfill_order(int q)
{

	if(q == 0)
	{
		return 0;
	}

	else if(q <= stock)
	{
		stock = stock - q;
		return q;
	}

	else
	{
		q = stock;
		stock = 0;
		return q;
	}
}

//printing function
void book::print() const
{
	cout << setw(14) << left << isbn;
	cout << setw(44) << left << title;
	cout << setw(5) << fixed << setprecision(2) << right << price;
	cout << setw(6) << right << stock << endl;
}
