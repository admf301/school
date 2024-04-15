
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXARGCOUNT 6
#define MAXCOMMANDSIZE 256

using namespace std;

//function prototype
void argvfill(char *cmd, char *argv[]);

int main()
{
	//define arrays to hold up to 255 chars + null char
	//define the commands argv
	char cmd1[MAXCOMMANDSIZE], cmd2[MAXCOMMANDSIZE];
	char *argv1[MAXARGCOUNT], *argv2[MAXARGCOUNT];

	//initializing the pipe and variables to hold return status's of system calls to error check
	int pipefd[2], rs = 0, status = 0;
	pid_t pid;

	//get first command
	cout << "command 1? ";
	cin.getline(cmd1, MAXCOMMANDSIZE);
	argvfill(cmd1, argv1);

	//get second command
	cout << "command 2? ";
	cin.getline(cmd2, MAXCOMMANDSIZE);
	argvfill(cmd2, argv2);

	//loop through commands until "END"
	while(strcmp(cmd1, "END") != 0 && strcmp(cmd2, "END") != 0)
	{
		//fork off to a child
		pid = fork();
		if(pid == -1)
		{
			perror("fork error");
			exit(1);
		}

		//the first child's function is to make a another child to represent the two input commands
		if(pid == 0)
		{
			//create a pipe within the child process
			rs = pipe(pipefd);
			if(rs == -1)
			{
				perror("pipe error");
				exit(1);
			}

			//fork the child with its pipe
			pid = fork();
			if(pid == -1)
			{
				perror("fork error");
				exit(1);
			}

			//child of the child (grandchild)
			if(pid == 0)
			{
				//close write end of pipe and stdin
				close(pipefd[1]);
				close(0);

				//duplicate read end of pipe into stdin and close the read end of the pipe
				dup(pipefd[0]);
				close(pipefd[1]);

				//execute the command
				rs = execvp(argv2[0], argv2);
				if(rs == -1)
				{
					perror("exe error");
					exit(1);
				}
			}

			else
			{
				//close the read end of the pipe and close stdout
				close(pipefd[0]);
				close(1);

				//duplicate write end of the pipe into stdout and close the write end of the pipe
				dup(pipefd[1]);
				close(pipefd[1]);

				//execute the command
				rs = execvp(argv1[0], argv1);
				if(rs == -1)
				{
					perror("exe error");
					exit(1);
				}

				//waiting for its child to finish before finishing itself
				pid = wait(&status);
				if(pid == -1)
				{
					perror("wait error");
					exit(1);
				}
			}
		}

		//waiting for child and its child before asking for new commands
		pid = wait(&status);
		if(pid == -1)
		{
			perror("wait error");
			exit(1);
		}

		//get new command 1
		cout << "command 1? ";
		cin.getline(cmd1, MAXCOMMANDSIZE);
		argvfill(cmd1, argv1);

		//get new command 2
		cout << "command 2? ";
		cin.getline(cmd2, MAXCOMMANDSIZE);
		argvfill(cmd2, argv2);
	}

	exit(0); //successful completion
}

//this function parses the command entered and fill a passed argv array with given options
//@param cmd is the command to be parsed
//@param argv[] argv array that will be filled with arguments
void argvfill(char *cmd, char *argv[])
{
	int count = 0;
	//strtok with " " delimeter
	char *token = strtok(cmd, " ");
	argv[0] = token;

	//loop until end
	while(token != NULL)
	{
		token = strtok(NULL, " ");
		argv[++count] = token;
	}
}
