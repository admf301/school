#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <errno.h>

using namespace std;

int main(int argc, char* argv[])
{
	int ifd, ofd;
	struct stat status;
	char filename[50];
	char whatToWrite[100];

   	//check arguments
   	if (argc < 2)
   	{
   		cout << "Usage:  secretfile [-c] out_file message_string" << endl;
		cout << '\t' << "where the message_string is appeneded to file out_file." << endl;
		cout << '\t' << "The -c option clears the file before the message is appended." << endl;
		exit(EXIT_FAILURE);
   	}

   	//open the file to be written into and creates it if it doesnt exist
   	//clear if -c is present
   	if (argc == 4 && (strcmp (argv[1],"-c") == 0))
   	{
   	    	strcpy (filename, argv[2]);
   	    	strcpy (whatToWrite, argv [3]);
   	    	ifd = open(filename , O_RDWR | O_TRUNC | O_CREAT, 00000);
   	}

	if(argc == 3)
   	{
		strcpy (filename, argv[1]);
       		strcpy (whatToWrite, argv [2]);
       		ifd = open(filename , O_RDWR | O_APPEND | O_CREAT, 00000);
//		cout << "ifd: " << ifd << endl;
//		cout << "idf errno: " << errno << endl;
   	}

   	else
   	{
		cout << "invalid arguments" << endl;
		exit(EXIT_FAILURE);
   	}

   	stat(filename, &status);
//  	cout << "stmode 777: " << (status.st_mode & 777) << endl;

	//checking permissions

   	if((status.st_mode & 777) != 0)
   	{
		cout << filename << " is not secure. Ignoring" << endl;
		exit(EXIT_FAILURE);
   	}
//   	cout << "st_mode after: " << (status.st_mode & 777) << endl;

	if((status.st_mode & 777) == 0)
	{
		ofd = write(ifd, whatToWrite, strlen(whatToWrite));
//		cout << "ofd: " << ofd << endl;
//		cout << "errno: " << errno << endl;
		close(ofd);
	}

	return 0;
}
