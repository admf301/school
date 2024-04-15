

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

/********************************************************************
Function: 	countUnique

Use:		Counts the number of unique integers within an array.		ex. input: {0, 0, 0, 0, 1, 1, 1, 1}
										    output: 2
Arguments: 	1. arr: the built "array" of integers parsed from the file.

Returns: 	The number of unique integers within the array.
********************************************************************/
int countUnique(const vector<int> &arr) {				//this is a helper function for finding the number of multi-core chips
        set<int> uniqueNumbers;						//since elements in a set are unique

        for(int num : arr) {
                uniqueNumbers.insert(num);				//the insert() method stores only unique elements
        }

        return uniqueNumbers.size();
}

int main() {
	string osType;							//variable declarations
	string hostName;
	string osRelease;
	string osVersion;
	string vendorName;
	string modelName;
	string pAddrSize;
	string vAddrSize;
	int numProcessors = 0;
	vector<int> physChips;
	int uptimeSeconds;
	int userTime;
	int systemTime;
	int idleTime;
	int swapSizeMB = 0;
									//most of these follow the same process:
	ifstream osTypeFile("/proc/sys/kernel/ostype");
	if(osTypeFile.is_open()) {					//open the specified file
		getline(osTypeFile, osType);				//extract the needed data from the file
		osTypeFile.close();					//close the file
	}

	ifstream hostNameFile("/proc/sys/kernel/hostname");
	if(hostNameFile.is_open()) {
		getline(hostNameFile, hostName);
		hostNameFile.close();
	}

	ifstream osReleaseFile("/proc/sys/kernel/osrelease");
	if(osReleaseFile.is_open()) {
		getline(osReleaseFile, osRelease);
		osReleaseFile.close();
	}

	ifstream osVersionFile("/proc/sys/kernel/version");
	if(osVersionFile.is_open()) {
		getline(osVersionFile, osVersion);
		osVersionFile.close();
	}

	ifstream numProcessorsFile("/proc/cpuinfo");
	if(numProcessorsFile.is_open()) {
		string line;						//the line currently being read

		while(getline(numProcessorsFile, line)) {		//while there are lines in the file left to read
			if(line.find("processor") != string::npos) {	//if the specified string is found
				numProcessors++;
			}
									//using substrings to break-up the line being read
			if(line.find("physical id") != string::npos) {
				physChips.push_back(stoi(line.substr(line.find(":") + 2)));
			}
									//the + 2 is to account for spacing between the ":" and the data
	                if(line.find("vendor_id") != string::npos) {
   	  	              	vendorName = line.substr(line.find(":") + 2);
               	        }

                       	if(line.find("model name") != string::npos) {
                       	        modelName = line.substr(line.find(":") + 2);
                       	}

                       	if(line.find("address sizes") != string::npos) {
                               	string pAddrSizeTemp = line.substr(line.find(":") + 2);
				string vAddrSizeTemp = line.substr(line.find(",") + 2);

				pAddrSizeTemp.erase(pAddrSizeTemp.begin() + 2, pAddrSizeTemp.end());
				pAddrSize = pAddrSizeTemp;

				vAddrSizeTemp.erase(vAddrSizeTemp.begin() + 2, vAddrSizeTemp.end());
				vAddrSize = vAddrSizeTemp;
                        }
		}
		numProcessorsFile.close();
	}

	ifstream uptimeFile("/proc/uptime");
	if(uptimeFile.is_open()) {
		uptimeFile >> uptimeSeconds;				//just need the 1st value
		uptimeFile.close();
	}

	ifstream statFile("/proc/stat");
	if(statFile.is_open()) {
		string line;

		while(getline(statFile, line)) {
			if(line.find("cpu5 ") != string::npos) {
				istringstream iss(line);		//easier to use a input stream because of how the file is formatted
				string cpuLabel;			//variable from iss input not used for printing

				iss >> cpuLabel >> userTime >> systemTime >> idleTime;
				break;					//continue on once data is found
			}
		}
		statFile.close();
	}

	ifstream swapsFile("/proc/swaps");
	if(swapsFile.is_open()) {
		string line;

		while(getline(swapsFile, line)) {
			if(line.find("/dev/") != string::npos) {
				istringstream iss(line);

				string swapName;			//variables from iss input not used for printing
				string swapType;
				int swapUsed;
				int swapPriority;

				int swapSize;
				iss >> swapName >> swapType >> swapSize >> swapUsed >> swapPriority;

				swapSizeMB = swapSize / 1000;		//swap size is in kilobytes by default
				break;					//continue on once data is found
			}
		}
		swapsFile.close();
	}
									//this is all output and formatting
	cout << endl;
	cout << "A: Questions about turing's OS:" << endl;
	cout << "1. The type of turing's OS is " << osType << "." << endl;
	cout << "2. Turing's hostname is " << hostName << "." << endl;
	cout << "3. The OS relsease of turing is " << osRelease << "." << endl;
	cout << "4. Turing's kernel version is " << osVersion << "." << endl;

	cout << endl;
	cout << "B: Questions about turing's processors:" << endl;
	cout << "1. Turing has " << numProcessors << " processors." << endl;
	int chips = countUnique(physChips);
	cout << "2. Turing has " << chips << " physical multi-core chips." << endl;
	cout << "3. Turing has been up for " << uptimeSeconds << " seconds." << endl;

        int uptimeDays = uptimeSeconds / 86400;				//calculating days/hours/minutes/seconds from total seconds
        uptimeSeconds %= 86400;
        int uptimeHours = uptimeSeconds / 3600;
        uptimeSeconds %= 3600;
        int uptimeMinutes = uptimeSeconds / 60;
        uptimeSeconds %= 60;
        int uptimeSec = uptimeSeconds % 60;

	cout << "4. Turing has been up for " << uptimeDays << " days, " << uptimeHours << " hours, " << uptimeMinutes << " minutes, and " << uptimeSec << " seconds." << endl;

	cout << endl;
	cout << "C: Questions about processor 0:" << endl;
	cout << "1. The vendor of processor 0 is " << vendorName << "." << endl;
	cout << "2. The model name of processor 0 is " << modelName << "." << endl;
	cout << "3. The Physcial Address Size of processor 0 is " << pAddrSize << " bits." << endl;
	cout << "4. The Virtual Address Size of processor 0 is " << vAddrSize << " bits." << endl;

	cout << endl;
	cout << "D: Questions about processor 5:" << endl;
	cout << "1. Processor 5 has spent " << userTime << " seconds in user mode." << endl;
	cout << "2. Processor 5 has spent " << systemTime << " seconds in system mode." << endl;
	cout << "3. Processor 5 has spent " << idleTime << " seconds in idle mode." << endl;

	int idleDays = idleTime / 86400;				//calculating days/hours/minutes/seconds from total seconds
	idleTime %= 86400;
	int idleHours = idleTime / 3600;
	idleTime %= 3600;
	int idleMinutes = idleTime / 60;
	idleTime %= 60;
	int idleSeconds = idleTime % 60;

	cout << "4. Processor 5 has spent " << idleDays << " days, " << idleHours << " hours, " << idleMinutes << " minutes, and " << idleSeconds << " seconds in idle mode." << endl << endl;

	cout << "E. Question about turing's swap device:" << endl;
	cout << "1. The size of turing's swap device is " << swapSizeMB << " MB." << endl;
	cout << endl;
	return 0;
}
