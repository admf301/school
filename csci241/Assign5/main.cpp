
#include <iostream>
#include "book_store.h"

using namespace std;

//main() is the driver function that creates a book_store object
int main()
{
	cout << endl;

	book_store test;

	test.read_book_data("bookdata");
	test.print();
	test.process_orders("orders.txt");
	test.print();

	return 0;
}
