
#ifndef BOOK_H
#define BOOK_H

#include <cstring>

using namespace std;

class book
{
private:
	//book definition
	char isbn[11]{"None"};
	char title[41]{"None"};
	double price{0.0};
	int stock{0};

public:

	//constructor
	book() = default;
	book(const char*, const char*, double, int);

	//prototype function declaration
	const char* get_isbn() const;
	double get_price() const;
	int fulfill_order(int);
	void print() const;
};

#endif
