#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &grid, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i > m - 1 or j > n - 1)
    {
        return INT_MAX;
    }
    if (i == m - 1 and j == n - 1)
    {
        return grid[m - 1][n - 1];
    }
    int rgt = solve(grid, i, j + 1);
    int down = solve(grid, i + 1, j);
    int ans = grid[i][j] + min(rgt, down);
    return ans;
}
int solveMemo(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i > m - 1 or j > n - 1)
    {
        return INT_MAX;
    }
    if (i == m - 1 and j == n - 1)
    {
        return grid[m - 1][n - 1];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int rgt = solveMemo(grid, i, j + 1, dp);
    int down = solveMemo(grid, i + 1, j, dp);
    int ans = grid[i][j] + min(rgt, down);
    dp[i][j] = ans;
    return dp[i][j];
}
int solveTab(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m - 1][n - 1] = grid[m - 1][n - 1];
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 and j == n - 1)
            {
                continue;
            }
            int rgt = dp[i][j + 1];
            int down = dp[i + 1][j];
            int ans = grid[i][j] + min(rgt, down);
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveSO(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> curr(n + 1, INT_MAX);
    vector<int> next(n + 1, INT_MAX);
    curr[n - 1] = grid[m - 1][n - 1];
    next[n - 1] = grid[m - 1][n - 1];
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 and j == n - 1)
            {
                continue;
            }
            int rgt = curr[j + 1];
            int down = next[j];
            int ans = grid[i][j] + min(rgt, down);
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    vector<vector<int>> grid;
    grid.push_back({1, 3, 1});
    grid.push_back({1, 5, 1});
    grid.push_back({4, 2, 1});
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << solve(grid, 0, 0) << endl;
    cout << solveMemo(grid, 0, 0, dp) << endl;
    cout << solveTab(grid) << endl;
    cout << solveSO(grid) << endl;
    return 0;
}