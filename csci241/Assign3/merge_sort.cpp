
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int builder(int array[])
{
	int n = 0;
	while(cin >> array[n])
		n++;

	return n;
}

void printer(int array[], int n)
{
	int p = 0;

	if(n % 8 == 0 && n < 100)
	{
		for(p = 1; p < n + 1; p++)
		{
			cout << setw(8) << array[p - 1] << setw(8);
			if(p % 8 == 0)
				cout << endl;
			else if(p == n)
				cout << endl;
		}
		p = 0;
	}

	if(n < 15 && n > 8)
	{
		for(p = 1; p < n + 1; p++)
		{
			cout << setw(8) << array[p - 1] << setw(8);
			if(p % 8 == 0)
				cout << endl;
			else if(p == n)
				cout << endl;
		}
		p = 0;
	}

	if(n < 8)
	{
		for(p = 1; p < n + 1; p++)
		{
			cout << setw(8) << array[p - 1] << setw(8);
			if(p == n)
				cout << endl;
		}
		p = 0;
	}

	if(n > 20 && n < 30)
	{
		for(p = 0; p < n; p++)
		{
			cout << setw(8) << array[p + 1] << setw(8);
			if((p + 1) % 8 == 0)
				cout << endl;
			else if(p == n - 1)
				cout << endl;
		}
	}

	if(n > 30 && n < 100)
	{
		for(p = 1; p <= n; p++)
		{
			cout << setw(8) << array[p - 1] << setw(8);
			if(p % 8 == 0)
				cout << endl;
			else if(p == n)
				cout << endl;
		}
		p = 0;
	}

	else if(n > 100)
	{
		for(p = 0; p < n; p++)
		{
			cout << setw(8) << array[p] << setw(8);
			if((p + 1) % 8 == 0)
				cout << endl;
			else if(p == n - 1)
				cout << endl;
		}
}

//the merge class sorts the original array by comparing the entries in the array and putting the sorted elements into a temporary array
//called temp[]. then puts the sorted contents of temp[] back into the original array.
//@param mid is the middle of start and finish
//@param start is the first entry in the array
//@param finish is the last entry in the array
void merge(int array[], int start, int mid, int finish)
{
	int temp[finish - start + 1];
	int i = start;
	int j = mid + 1;
	int k = 0;

	while(i <= mid && j <= finish)
	{
		if(array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
			k++;
		}

		else
		{
			temp[k] = array[j];
			j++;
			k++;

		}

	}

	while(i <= mid)
	{
		temp[k] = array[i];
		i++;
		k++;

	}

	while(j <= finish)
	{
		temp[k] = array[j];
		j++;
		k++;

	}

	for(i = start; i <= finish; i++)
		array[i] = temp[i - start];
}

//merge_sort cuts the main array in half, then sorts the halves, then the merge class puts them back into the original array.
//@param array[] is the incoming array
//@param start is the first entry of the array
//@param finish is the last entry of the array
void merge_sort(int array[], int start, int finish)
{
	if(start < finish)
	{
		int mid = (start + finish) / 2;

		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, finish);

		merge(array, start, mid, finish);
	}
}

int main()
{
	int n;
	int numbers[1000];
	n = builder(numbers);

	merge_sort(numbers, 0, n);
	printer(numbers, n);

	return 0;
}
