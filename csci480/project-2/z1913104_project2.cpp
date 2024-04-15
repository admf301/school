
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstdlib>

using namespace std;

/********************************************************************
Function: 	fcfs

Use:		Handles all FCFS command functionality of the shell

Arguments: 	1. processes: 	number of simulated processes
		2. output_file:	the output file to write the output to

Returns: 	nothing
********************************************************************/
void fcfs(int processes, const string& output_file) {
	srand(10); 							//set random seed to 10
	int burst_calc[processes];					//array to store generated CPU bursts
	int current_sum = 0;						//calculation variables
	int total_wait = 0;

	for(int i = 0; i < processes; i++) {
		int burst = rand() % 100 + 1;				//this loop generates the cpu bursts
		burst_calc[i] = burst;					//and adds them to the calculation array
	}

	for(int j = 0; j < processes - 1; j++) {
		current_sum += burst_calc[j];				//this loop calculates the FCFS schuduling waiting time
		total_wait += current_sum;
	}

	int average_wait = total_wait / processes;

	if(!output_file.empty()) {					//if output redirection, write to the specified file
		int fd2 = open(output_file.c_str(), O_WRONLY | O_CREAT, 0644);
		if(fd2 == -1) {
			cerr << "cannot open specified file" << endl;
			exit(1);
		}
		int original_stdout = dup(STDOUT_FILENO);		//save the original stdout to return to
		dup2(fd2, STDOUT_FILENO);				//redirect stdout to the selected file
									//print the fcfs output in the file
		cout << "FCFS CPU scheduling simulation with " << processes << " processes." << endl;
		for(int i : burst_calc) {
			cout << "CPU burst: " << i << " ms" << endl;
		}
		cout << "Total waiting time in the ready queue: " << total_wait << " ms" << endl;
		cout << "Average waiting time in the ready queue: " << average_wait << " ms" << endl;

		close(fd2);
		dup2(original_stdout, STDOUT_FILENO);			//restore stdout to its previous state (back to console)
		close(original_stdout);
	}

	else {								//fcfs formatted output
		cout << "FCFS CPU scheduling simulation with " << processes << " processes." << endl;
		for(int i : burst_calc) {
			cout << "CPU burst: " << i << " ms" << endl;
		}
		cout << "Total waiting time in the ready queue: " << total_wait << " ms" << endl;
		cout << "Average waiting time in the ready queue: " << average_wait << " ms" << endl;
	}
}

int main() {

	while(true) {

		cout << "myshell>";
		string input;
		getline(cin, input);					//get the input

		if(input.empty()) {
			continue;					//repeat the prompt if input is empty
		}

		if(input == "quit" || input == "q") {
			break;						//exit the shell
		}

		stringstream ss(input);					//tokenize the input
		vector<string> args;
		string token;

		while(ss >> token) {
			args.push_back(token);				//build the args array
		}


		if(args[0] == "fcfs") {					//check for special fcfs command
			int processes = 5; 				//defaults to 5
			string output_file;
			bool error  = false;

			for(size_t i = 0; i < args.size(); i++) {	//check for output redirection
				if(args[i] == ">") {

					if(i + 1 < args.size()) {		//check for specified file
						output_file = args[i + 1];	//assign specified file
						break;
					}

					else {
						cerr << "fcfs: output file not specified" << endl;
						error = true;
						continue;
					}
				}
			}

			if(args.size() > 1 && args[1] != ">") {		//check for speficied process count

				try {					//make sure the entered argument is an integer
					processes = stoi(args[1]);
				}
				catch(const exception&) {
					error = true;
					cerr << "fcfs: argument must be an integer" << endl;
				}
			}

			if(error == false) {
				fcfs(processes, output_file);		//execute the command
			}
		}

		else {
			bool redirect = false;
			string output_file;

			for(size_t i = 0; i < args.size(); i++) {	//check for output redirection
				if(args[i] == ">") {

					if(i + 1 < args.size()) {				//check for specified file
						redirect = true;
						output_file = args[i + 1];			//assign specified file
						args.erase(args.begin() + i, args.end());	//clean up args vector for argv/execvp
						break;
					}

					else {
						cerr << "myshell: output file not specified." << endl;
						continue;
					}
				}
			}

			pid_t pid = fork();
			if(pid == -1) {
				cerr << "fork error" << endl;
			}

			if(pid == 0) {
				char *argv[args.size() + 1];		//build the argv array
				for(size_t i = 0; i < args.size(); i++) {
					argv[i] = const_cast<char*>(args[i].c_str());
				}

				argv[args.size()] = NULL;		//format for execvp

				if(redirect) {
					int fd = open(output_file.c_str(), O_WRONLY | O_CREAT, 0644);
					if(fd == -1) {
						cerr << "cannot open specified file" << endl;
						exit(1);
					}
					dup2(fd, STDOUT_FILENO);
					close(fd);
				}

				if(execvp(argv[0], argv) == -1) {	//execute the command
					cerr << "couldn't execute: " << argv[0] << endl;
					exit(1);
				}
			}

			else {
				int status;
				waitpid(pid, &status, 0);
			}
		}
	}
	return 0;
}


















