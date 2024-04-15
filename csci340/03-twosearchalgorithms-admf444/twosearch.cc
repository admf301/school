
#include "twosearch.h"

#include <getopt.h>

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

/**
* see:
* https://en.wikipedia.org/wiki/Usage_message
* https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
*
* @param a0 The value of argv[0] (the name of the command) so that it
*   can be printed.
*
* @note This function will terminate the application via exit(1).
******************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/**
* Parse the command-line args, create and sort vector A, create vector B,
* search vector A for those elements appearing in vector B using both
* a linear and binary search, and print the hit-rate (the percentage of
* items in B that have been located in A.)
*
* If an invalid command-line arg is encountered, print a Usage statement
* and terminte with an exit-status of 1.
*
* @return zero
******************************************************************************/
int main(int argc, char **argv)
{
    // Demonstrate the use of getopt() to override default config parameters
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt = getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1)
    {
        switch(opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
            b_seed = std::stoi(optarg);
            break;

        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...

	std::vector<int> A(a_size);
	std::vector<int> B(b_size);

	init_vector(A, a_seed, rand_low, rand_high);
	init_vector(B, b_seed, rand_low, rand_high);

	std::cout << "A vector:" << std::endl;
	print_vector(A, print_cols, col_width);

	sort_vector(A);

	std::cout << std::endl << "A vector sorted:" << std::endl;
	print_vector(A, print_cols, col_width);

	std::cout << std::endl << "B vector:" << std::endl;
	print_vector(B, print_cols, col_width);

	std::cout << std::endl << "Linear Search: Percent of Successful Searches = ";
	int count = search_vector(A, B, linear_search);
	print_stat(count, B.size());

	std::cout << "Binary Search: Percent of Successful Searches = ";
	count = search_vector(A, B, binary_search);
	print_stat(count, B.size());

    return 0;

} // End of main()

/**
* Initialize vector function
*
* Assigns a random valued element in the vector vec using the seed value.
*
* @param vec - vector to be initialized
* @param seed - value that affects the random generation of numbers
* @param lo - low bound for generated numbers
* @param hi - high bound for generated numebrs
**********************************************************************************/
void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
	srand(seed);

	for(size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = rand()%(hi - lo + 1) + lo;
	}
}

/**
* Printing function
*
* Prints a formatted box displaying the contents of a vector
*
* @param v - vector to be printed
* @param print_cols - number of columns to display
* @param col_width - set column width to display
**********************************************************************************/
void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{
	size_t pdash = (col_width + 2) * print_cols; // pdash - number of (-) characters to display at the top and bottom of each box
	size_t numbox = v.size() / print_cols;	     // numbox and mult are used to count the number of (|) characters to backfill
	size_t mult = (numbox + 1) * print_cols;     // at the end of each box to make them rectangular

	size_t ccount = 0;			     // ccount and end are both used as flags essentially
	bool end = false;			     // to know when to backfill the box

	for(size_t p = 0; p <= pdash; p++)
	{
		std::cout << '-';
	}

	std::cout << std::endl;

	for(size_t i = 0; i < v.size(); i++)
	{
		std::cout << "|" << std::setw(col_width) << v[i] << " ";

		ccount++;
		end = false;

		if((i + 1) % print_cols == 0)
		{
			std::cout << "|" << std::endl;
			end = true;
		}
	}

	if(ccount == v.size() && end == false)
	{
		for(size_t j = 0; j < (mult - v.size()); j++)
		{
			std::cout << "|" << std::setw(col_width) << " " << " ";

			if((j + 1) % (mult - v.size()) == 0)
			{
				std::cout << "|" << std::endl;
			}
		}
	}

	for(size_t q = 0; q <= pdash; q++)
	{
		std::cout << '-';
	}
}

/**
* Sorting function
*
* Sorts the input vector in ascending order using the STL function std::sort()
*
* @param v - vector to be sorted
**********************************************************************************/
void sort_vector(std::vector<int> &v)
{
	std::sort(v.begin(), v.end());
}

/**
* Search vector function
*
* Each element of v2 is searched for in v1
* counts the number of successful searches
*
* @param v1 - vector 1 to be searched
* @param v2 - vector 2 to be searched
* @param p() - pointer to the search routine
* @return - the number of successful searches
**********************************************************************************/
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{
	int count = 0;

	for(size_t i = 0; i < v2.size(); i++)
	{
		if(p(v1, v2[i]))
		{
			count++;
		}
	}

	return count;
}

/**
* Print stat function
*
* Calculate and print the percent of successful searches
*
* @param found - number of successful searches
* @param total - size of searched vector
**********************************************************************************/
void print_stat(int found, int total)
{
	std::cout << std::fixed << std::setprecision(2) << ((double)found * 100) / total << "%" << std::endl;
}

/**
* Linear search function
*
* Determines if the value (x) is found within the vector v
*
* @param v - vector to be searched
* @param x - value to be searched for
* @return true - if value is found within the vector
* @return false - if value is not found within the vector
**********************************************************************************/
bool linear_search(const std::vector<int> &v, int x)
{
	if(std::find(v.begin(), v.end(), x) != v.end())
	{
		return true;
	}

	return false;
}

/**
* Binary search function
*
* Determines if the value (x) is found within the vector v
*
* @param v - vector to be searched
* @param x - value to be searched for
* @return true - if value is found within the vector
* @return false - if value is not found within the vector
**********************************************************************************/
bool binary_search(const std::vector<int> &v, int x)
{
	return (binary_search(v.begin(), v.end(), x));
}
