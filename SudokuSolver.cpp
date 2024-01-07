#include <bits/stdc++.h>
using namespace std;
#define N 9
class Solution
{
public:
    bool isSafe(int row, int col, int grid[N][N], int val)
    {
        for (int i = 0; i < 9; i++)
        {
            if (grid[row][i] == val)
            {
                return false;
            }
            if (grid[i][col] == val)
            {
                return false;
            }
            if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])
    {
        int row, col;

        // Check if the Sudoku puzzle is already solved
        bool isSolved = true;
        for (row = 0; row < N; row++)
        {
            for (col = 0; col < N; col++)
            {
                if (grid[row][col] == 0)
                {
                    isSolved = false;
                    break;
                }
            }
            if (!isSolved)
            {
                break;
            }
        }

        if (isSolved)
        {
            return true;
        }

        for (int k = 1; k <= 9; k++)
        {
            if (isSafe(row, col, grid, k))
            {
                grid[row][col] = k;
                if (SolveSudoku(grid)) // Recursive call
                {
                    return true;
                }
                else
                {
                    grid[row][col] = 0; // Backtrack
                }
            }
        }
        return false;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        if (SolveSudoku(grid))
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}