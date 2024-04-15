
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "book_store.h"

using namespace std;

//constructor
book_store::book_store()
{
	valid_book_data = 0;
}

//read_book_data() creates the book_array of size valid_book_data
//@param const string& file_name = name of input file
void book_store::read_book_data(const string& file_name)
{
	//open file and test for failure
	ifstream in_file;
	in_file.open(file_name);
	if(!in_file)
	{
		cerr << "error - ISBN " << file_name << "does not exist" << endl;
	}

	//read the data from the file into the book_array
	in_file.read((char*) &book_array[valid_book_data], sizeof(book));

	while(in_file)
	{
		valid_book_data++;

		in_file.read((char*) &book_array[valid_book_data], sizeof(book));
	}

	//sort the book_array and close the file.
	sort_book_list();
	in_file.close();
}

//sort_book_list() sorts the book objects by ascending ISBN
void book_store::sort_book_list()
{
	int i, j, min;
	book temp;

	for(i = 0; i < valid_book_data - 1; i++)
	{
		min = i;

		for(j = i + 1; j < valid_book_data; j++)
		{
			if(strcmp(book_array[j].get_isbn(), book_array[min].get_isbn()) < 0)
			{
				min = j;
			}
		}

		temp = book_array[i];
		book_array[i] = book_array[min];
		book_array[min] = temp;
	}
}

//binary_search() will scan through a sorted array comparing the (ISBN) search_key to the middle element of the book_array
//@param book book_array[] is the array containing the book objects
//@param length is the number of entries in book_array
//@param search_key is the element you are looking for
//@returns -1 on unsuccessful search
//@returns mid, or the found ISBN, on a successful search
int binary_search(book book_array[], int length, char* search_key)
{
	int low = 0;
	int high = length - 1;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if(strcmp(search_key, book_array[mid].get_isbn()) == 0)
		{
			return mid;
		}

		if(strcmp(search_key, book_array[mid].get_isbn()) < 0)
		{
			high = mid - 1;
		}

		else
		{
			low = mid + 1;
		}
	}

	return -1;
}

//process_orders() will read transaction data from a file (file_name), calculate the price and remaining stock of a book object, then print a header and the output.
//@param const string& file_name represents the input file.
void book_store::process_orders(const string& file_name)
{
	ifstream in_file;
	char order_num[10];
	char isbn[10];
	int ship_num;
	int element;
	int found_element = 0;

	cout << "Order Listing" << endl << endl;

	//open the selected file and test for successful file open
	in_file.open(file_name);

	if(!in_file)
	{
		cerr << "error unable to open orders file" << endl;
	}

	in_file >> order_num;
	while(in_file)
	{
		//@var int q (quantity) is the number of book objects available to sell
		int q;

		in_file >> isbn;
		in_file >> ship_num;

		element = binary_search(book_array, valid_book_data, isbn);

		if(element != -1)
		{

			found_element++;

			if(found_element < 10)
			{
				q = book_array[element].fulfill_order(ship_num);

				cout << "Order #10100" << found_element << ": " << "ISBN " << isbn << ", ";
				cout << q << " of " << ship_num << " shipped, ";
				cout << "order total $" << fixed << setprecision(2) << q*book_array[element].get_price() << endl;
			}

			else
			{
				q = book_array[element].fulfill_order(ship_num);

				cout << "Order #101010: ISBN " << isbn << ", ";
				cout << q << " of " << ship_num << " shipped, ";
				cout << "order total $" << fixed << setprecision(2) << q*book_array[element].get_price() << endl;
			}
		}

		else
		{
			found_element++;
			cout << "Order #10100" << found_element << ": " <<  "error - ISBN " << isbn << " does not exist" << endl;
		}

		in_file >> order_num;
	}

	in_file.close();
	cout << endl;
}

//print() const will print a report header, and then loop through and print each element of book_array
void book_store::print() const
{
	int i;
	cout << "Book Inventory Listing" << endl << endl;
	cout << setw(14) << left << "ISBN";
	cout << setw(44) << left << "Title";
	cout << setw(5) << right << "Price  ";
	cout << setw(6) << right << "Qty." << endl << endl;

	for(i = 0; i < valid_book_data; i++)
	{
		book_array[i].print();
	}

	cout << endl;
}
