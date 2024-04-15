
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>

#include "dogfunc.h"

using namespace std;

//flags for arguments and place to store values for arguments
bool sflag, nflag, cflag, rflag, xflag, bflag;
char *svalue;
char *nvalue;
char *cvalue;
char *rvalue;

//prototypes
void cat(int fd);
void dog(char str[], int numbers_read);

int main(int argc, char *argv[])
{
	int opt;
	while((opt = getopt(argc, argv, "s:n:c:r:xb")) != -1)
	{
		switch(opt)
		{
			//when an option is selected, set a flag for that option and set the supplied option to optarg.
			case 's':
				sflag = true;
				svalue = optarg;
				break;

			case 'n':
				nflag = true;
				nvalue = optarg;
				break;

			case 'c':
				cflag = true;
				cvalue = optarg;
				break;

			case 'r':
				rflag = true;
				rvalue = optarg;
				break;

			case 'x':
				xflag = true;
				break;

			case 'b':
				bflag = true;
				break;

			default:
				cerr << "invalid argument" << endl;
				exit(1);
		}
	}

	//invalid combination of arguments
	if(rflag && cflag)
	{
		cerr << "invalid combination of arguments -r -c" << endl;
		exit(1);
	}

	else if(bflag && xflag)
	{
		cerr << "invalid combination of arguments -b -x" << endl;
		exit(1);
	}

	//no file specified use stdin
	if(argc == optind || strcmp(argv[optind], "-") == 0)
	{
		cat(0);
	}

	else
	{
		int fd;

		//loop through arguments in command line
		for(int i = optind; i < argc; i++)
		{
			//open selected file
			if((fd = open(argv[i], O_RDONLY, 0644)) == -1)
			{
				perror("open error");
				exit(1);
			}

			//concatenate then close the selected file.
			cat(fd);
			close(fd);
		}
	}

	exit(0);
}

//this method concatenates text and nontext to stdout
//@param fd is the file descriptor to read from
void cat(int fd)
{
	ssize_t number_read;

	//creating the buffer, and if -s N is supplied use N
	int buffersize = sflag ? stoi(svalue) : 256;
	char buffer[buffersize];

	if(nflag)
	{
		//read the selected file up until -n option value
		if((number_read = read(fd, buffer, stoi(nvalue))) == -1)
		{
			perror("read error");
			exit(1);
		}

		//write using dog()
		dog(buffer, number_read);
	}

	else
	{
		//read until end of file
		while((number_read = read(fd, buffer, buffersize)) != 0)
		{
			if(number_read == -1)
			{
				perror("read error");
				exit(1);
			}

			//write using dog()
			dog(buffer, number_read);
		}
	}
}

//this method checks data processing options and writes to stdout
//@param buffer is the buffer to be manipulated
//@param number_read is the amount of characters that are in the buffer
void dog(char buffer[], int number_read)
{
	if(cflag)// if -c is supplied
	{
		caesarCipher(buffer, number_read, stoi(cvalue));
	}

	else if(rflag)// if -r is supplied
	{
		rotation(buffer, number_read, stoi(rvalue));
	}

	if(bflag)// if -b is supplied
	{
		//empty binary buffer that contains translated characters
		char binary[number_read * 8];
		toBinary(buffer, number_read, binary);

		//write the new buffer
		if(write(1, binary, number_read * 8) == -1)
		{
			perror("write error");
			exit(1);
		}
	}

	else if(xflag)// if -x is supplied
	{
		//empty hex buffer that contains the translated characters
		char hex[number_read * 2];
		toHex(buffer, number_read, hex);

		//write the new buffer
		if(write(1, hex, number_read * 2) == -1)
		{
			perror("write error");
			exit(1);
		}
	}

	else//write the buffer like cat would
	{
		if(write(1, buffer, number_read) == -1)
		{
			perror("write error");
			exit(1);
		}
	}
}
