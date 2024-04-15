
#include <iostream>

using namespace std;

#define N 8
int n = 8;

class queen_solver
{
private:

    bool board[N][N] = {{false}};

public:

    queen_solver() = default;
    bool place_queens();
    bool place_queen_in_row(int);
    bool is_safe(int, int) const;
    void print_solution(int) const;
};


int main()
{
    queen_solver q;

    if (q.place_queens())
       q.print_solution(n);
    else
        cout << "Error - no solution found\n";

    return 0;
}

bool queen_solver::place_queens()
{
    return place_queen_in_row(0);
}

bool queen_solver::place_queen_in_row(int row)
{
    // Base case #1 - All queens have been placed successfully.
    if (row >= 8)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (is_safe(row, col))
        {
           board[row][col] = 1;  // Put a queen (the number 1) at board[row][col]

            if (place_queen_in_row(row + 1)) //recursion
                // Base case #2 - All queens in rows below this one
                // have been successfully placed.
                return true;

           board[row][col] = 0; // Remove the queen at board[row][col]
        }
    }

    // Base case #3 - We were not able to place a queen anywhere in
    // this row.
    return false;
}

bool queen_solver::is_safe(int row, int col) const
{
    for(int i = 0; i < row; i++)
	if(board[i][col])
		return false;	 // Check the rows above this column. col stays the same, row varies
   				 // from row - 1 down to 0.

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	if(board[i][j])
		return false;	 // Check the left diagonal above this row. col varies from col - 1
   				 // down to 0, row varies from row - 1 down to 0.

    for(int i = row, j = col; i >= 0 && j < N; i--, j++)
	if(board[i][j])
		return false;	 // Check the right diagonal above this row. col varies from col + 1
   				 // up to 7, row varies from row - 1 down to 0.

    return true;
}

void queen_solver::print_solution(int n) const
{
    for(int i = 0; i < n; i++)	//the printer function prints the values stored in the array board[][]
    {				//in an 8x8 chess board grid
	for(int j = 0; j < n; j++)
	{
		cout << board[i][j] << " ";
	}

	cout << endl;
    }
}

