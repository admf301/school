

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>

using namespace std;

//@param argc and argv are the standard parameters for main.
//@param argc counts the number of arguments entered into the command line
//@param argv[] contains the contents of what was entered into the command line

int main(int argc, char* argv[])
{
	int i;

	for(i = 1; i < argc; i++) //iterate through all command line arguments
	{
		const char* fn = argv[i]; //input the command line arguments, in this case the filename, one at a time into the variable

		if(strcmp(argv[i], "-") == 0) //if "-" is entered into the command line argument we use standard input
		{
			cout << cin.rdbuf();
		}

		fstream f;
		f.open(fn); //after confirming we are not using standard input, open the selected file from the command line

		if(!fn) //if cannot find filename, or file does not exist
		{
			cout << "error, cannot find file with that name" << endl;
			return -1;
		}

		else //else, print the contents of the selected file
		{
			f.seekg(0, f.end);      //go to end of file
			int length = f.tellg(); //define the length of the file
			f.seekg(0, f.beg);	//go to beginning of file
			char* buffer = new char[length]; //create buffer the size of length for file contents to be read into

			f.read(buffer, length); //read the file contents into the buffer until the end of the file

			cout << buffer;
		}

		f.close(); //close the selected file
	}

	return 0;
}
