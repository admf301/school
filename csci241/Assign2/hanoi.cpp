
#include <iostream>

using namespace std;

void move(int, int, int, int);

int main(int argc, char *argv[])
{

    int n_disks = stoi(argv[1]); //take the first argument convert it to an int and take it as the number of disks.

    move(n_disks, 1, 2, 3);

    return 0;
}

void move(int n_disks, int src_peg, int dest_peg, int temp_peg)
{

    if(n_disks == 1) //if there is only 1 disk, there is only 1 solution
    {                //this is the base case.
	cout << n_disks << " " << src_peg << "->" << dest_peg << endl;
    }

    else	     //move the smaller (n - 1) disk from the src_peg to the temp_peg -> move the bigger disk from the src_peg to the dest_peg
    {		     // -> move the smaller disk from the temp_peg to the dest_peg then repeat.
	move(n_disks - 1, src_peg, temp_peg, dest_peg);

	cout << n_disks << " " << src_peg << "->" << dest_peg << endl;

	move(n_disks - 1, temp_peg, dest_peg, src_peg);
    }

}
