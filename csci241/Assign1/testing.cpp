#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
#include <deque>
#include <set>

/*  */
using namespace std;

int main()
{
	vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	vector<char> v2 = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	std::copy(v1.begin(), v1.end(), v2.begin()+1);

	for(size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	return 0;
}
