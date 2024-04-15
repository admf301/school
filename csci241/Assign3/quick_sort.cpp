
#include <iostream>
#include <iomanip>

using namespace std;

int builder(int array[])
{
	int n = 0;
	while(cin >> array[n])
		n++;

	return n;

}

void printer(int numbers[], int n)
{
	int p;

	for(p = 1; p < n + 1; p++)
	{
		cout << setw(8) << numbers[p - 1] << setw(8);
			if(p % 8 == 0)
				cout << '\n';
			else if(p == n)
				cout << '\n';
	}

}
//function for swapping array indexes
// @param int* a and int* b point to array indexes.
void swap(int* a, int* b)
{
	int temp = *a;
    	*a = *b;
    	*b = temp;
}

//this function partitions the main array by a pivot point, then puts all smaller elements to the left of the pivot
//and puts all the larger elements to the right of the pivot.
//@param numbers[] is the incoming array
//@param low is the first entry in the array
//@param high is the last entry int he array
int partition(int numbers[], int low, int high)
{
    	int mid = (low + high) / 2;
    	swap(numbers[low], numbers[mid]);

    	int pivot_index = low;
    	int pivot_value = numbers[low];

    	int scan = low + 1;

	while(scan <= high)
    	{
		if(numbers[scan] < pivot_value)
		{
			pivot_index++;
			swap(numbers[pivot_index], numbers[scan]);

		}

		scan++;
    	}

    	swap(numbers[low], numbers[pivot_index]);

    	return pivot_index;

}
//this function uses the partition function to split the main array in half around the pivot point, and sorts the entries in each subarray
//from least to greatest until the entire originial array is sorted.
//@params are the same as partition()
void quickSort(int numbers[], int low, int high)
{
    	if (low < high)
    	{
        	int pivot_point = partition(numbers, low, high);

        	quickSort(numbers, low, pivot_point - 1);
        	quickSort(numbers, pivot_point + 1, high);
    	}
}

int main()
{
	int numbers[1000];
    	int n;
    	n = builder(numbers);

    	quickSort(numbers, 0, n-1);
    	printer(numbers, n);

    	return 0;
}
