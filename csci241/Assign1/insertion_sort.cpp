
#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

int builder(int[]);
void ISsorter(int[], int);
void printer(int[], int);

/*
*the builder class inputs data into an array.
*the ISsorter class is the main insertion sort algorithm that ingests data from the array and sorts the data in ascending order.
*the printer class prints the sorted output in columns of 8 integers.
*/

/*
*the main class is where it builds the list of integers from input, then uses the sorting function to sort the integers in ascending order,
*then prints the sorted output.
*@int numbers[] is the array where the values of the input are stores in order to be sorted.
*@int n is the number of entries in the array numbers[].
*will return 0 on a successful completion.
*/

int main(){

	int numbers[1000];
	int n;

	n = builder(numbers);
	ISsorter(numbers, n);
	printer(numbers, n);

	return 0;
}

/*
*the builder class builds a list of integers from input by storing them in an array.
*@param array is the array that reads the list of integers from input.
*@int n is the number of entries in array[].
*will return the number of integers stored in array[].
*/

int builder(int array[])
{

	int n = 0;

	while(cin >> array[n])
	{
		n++;
	}

	return n;
}

/*
*the ISsorter class sorts the list of integers in ascending order by using the insertion sort algorithm
*@param array is the list of integers to be sorted
*@param n is the number of entries in array[].
*/

void ISsorter(int array[], int n)
{
	int j;
	int i = 1;

	/*
	this nested while loop repeatedly inserts the current unsorted entry into the correct sorted position by comparing
	the current entry to the previous entry and swapping the entries if the current entry is smaller than the previous entry.
	*/

	while(i < n)
	{
		j = i;

		while(j > 0 && array[j - 1] > array[j])
		{
			swap(array[j - 1], array[j]);
			j = j - 1;
		}

		i = i + 1;
	}

}

/*
*the printer class prints the sorted list of integers in columns of 8 integers and will begin a new line once the list is finished printing.
*@param array is the list of sorted integers to print.
*@param n is the number of entries in array[].
*/

void printer(int array[], int n)
{
	int p;

	for(p = 1; p < n + 1; p++)
	{
		cout << setw(8) << array[p - 1] << setw(8);
			if(p % 8 == 0) //if we are at the 8th entry in the row, make a new line.
				cout << '\n';
			if(p == n)     //if we are at the end of the array, make a new line.
				cout << '\n';
	}

}




