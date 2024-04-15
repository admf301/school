
#include <sys/types.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/stat.h>
#include <string>
#include <fcntl.h>

using namespace std;

//removes trailing newline or carrige return from string s
void remove_trail(char *s)
{
	for(char *p = s + strlen(s) - 1; *p == '\r' || *p == '\n'; p--)
	{
		*p = '\0';
	}
}

int main(int argc, char *argv[])
{
	//MUST specify port and directory
	if(argc != 3)
	{
		cerr << "error usage: ./z1913104 port directory" << endl;
		exit(1);
	}

	char buffer[257];
	char path[256];
	socklen_t serverlen, clientlen;
	ssize_t recieved;
	int sock, new_sock;
	struct sockaddr_in echoserver; //structure for the address of the server
	struct sockaddr_in echoclient;
	struct stat s;

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("failed to create socket");
		exit(1);
	}

	//construct the server sockaddr_in structure
	memset(&echoserver, 0, sizeof(echoserver)); //clear
	echoserver.sin_family = AF_INET; //internet IP
	echoserver.sin_addr.s_addr = INADDR_ANY; //any IP address
	echoserver.sin_port = htons(atoi(argv[1])); //server port

	//bind the socket
	if(bind(sock, (struct sockaddr*)&echoserver, sizeof(echoserver)) < 0)
	{
		perror("failed to bind server socket");
		exit(1);
	}

	//listen -> make socket passive and set klength of queue
	if(listen(sock, 64) < 0)
	{
		perror("failure in listen");
		exit(1);
	}

	if(stat(argv[2], &s) == -1)
	{
		perror("failure in stat");
		exit(1);
	}

	if(!S_ISDIR(s.st_mode))
	{
		perror("argument must be directory");
		exit(1);
	}

	clientlen = sizeof(echoclient);
	new_sock = accept(sock, (struct sockaddr*)&echoclient, &clientlen);
	struct stat path_s;

	//fork to handle client (child)
	int pid = fork();

	if(pid == 0)
	{
		cout << "Client connected: " << inet_ntoa(echoclient.sin_addr) << endl;
		char path[256];
		if((recieved = read(new_sock, path, sizeof(path))) < 0)
		{
			perror("failed to recieve message");
			exit(1);
		}

		path[recieved] = '\0';
		remove_trail(path);
		string st(path);
		char *pathname = strcat(argv[2], st.substr(st.find("/")).c_str());

		//check if it exists
		if(stat(pathname, &path_s) != -1)
		{
			//is it a dir?
			if(S_ISDIR(path_s.st_mode))
			{
				//does this dir contain index.html
				struct stat indexcheck;
				char buf[1024];
				strcpy(buf, pathname);
				strcat(buf, "/index.html");

				if(stat(buf, &indexcheck) != -1)
				{
					//print contents of index.html
					int fd;
					if((fd = open(buf, O_RDONLY, 0644)) == 1)
					{
						perror("open");
						exit(1);
					}

					int number_read;
					while((number_read = read(fd, buffer, 256)) != 0)
					{
						if(number_read == -1)
						{
							perror("read");
							exit(1);
						}

						if(write(new_sock, buffer, number_read) == -1)
						{
							perror("write");
							exit(1);
						}
					}

					cout << endl;
					close(fd);
				}

				else
				{
					//print everything from dir
					DIR *dirp = opendir(pathname);
					if(dirp == 0)
					{
						perror("failure opening dir: ");
						exit(1);
					}

					//getting all entries
					struct dirent *dir_entry;
					while((dir_entry = readdir(dirp)) != NULL)
					{
						if(dir_entry->d_name[0] != '.')
						{
							strcpy(buffer, dir_entry->d_name);
							strcat(buffer, ", ");

							if(write(new_sock, buffer, strlen(buffer)) < 0)
							{
								perror("error in write: ");
								exit(1);
							}
						}
					}

					closedir(dirp);
					close(new_sock);
					exit(0);
				}
			}

			else if(S_ISREG(path_s.st_mode))
			{
				//this is a reg file - print the contents
				int fd;
				if((fd = open(pathname, O_RDONLY, 0644)) == -1)
				{
					perror("open");
					exit(1);
				}

				int number_read;
				while((number_read = read(fd, buffer, 256)) != 0)
				{
					if(number_read == -1)
					{
						perror("read");
						exit(1);
					}

					if(write(new_sock, buffer, number_read) == -1)
					{
						perror("write");
						exit(1);
					}
				}

				close(fd);
			}
		}

		else
		{
			//file or dir does not exist
			perror("file not found");
			exit(1);
		}
	}

	else
	{
		//parent
		close(new_sock);
	}

	//close connection
	close(sock);
}


