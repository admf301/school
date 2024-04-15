
#ifndef BOOK_STORE_H
#define BOOK_STORE_H

#include <string>
#include "book.h"

class book_store
{
private:
	//book_store definition
	book book_array[30];
	int valid_book_data{0};

	//utility prototype function declaration
	void sort_book_list();

public:

	//constructor
	book_store();

	//prototype function declaration
	void read_book_data(const std::string&);
	void process_orders(const std::string&);
	void print() const;
};

#endif
