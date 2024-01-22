#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Number of unique paths possible for a robot to move from grid[0][0] to grid[m-1][n-1] by moving only towards right or down
int solve(int m, int n)
{
    if (m == 0 and n == 0)
    {
        return 1;
    }
    if (m < 0 or n < 0)
    {
        return 0;
    }
    int right = solve(m, n - 1);
    int down = solve(m - 1, n);
    return right + down;
}
int solveMemo(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 and n == 0)
    {
        return 1;
    }
    if (m < 0 or n < 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int right = solveMemo(m, n - 1, dp);
    int down = solveMemo(m - 1, n, dp);
    dp[m][n] = right + down;
    return dp[m][n];
}
int solveTab(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int right = 0;
            int down = 0;
            if (j > 0)
                right = dp[i][j - 1];
            if (i > 0)
                down = dp[i - 1][j];
            dp[i][j] = right + down;
        }
    }
    return dp[m][n];
}
int solveSO(int m, int n)
{
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<int> curr(n + 1, 0);
    vector<int> prev(n + 1, 0);
    curr[0] = 1;
    prev[0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 and j == 0)
            {
                curr[j] = 1;
                prev[j] = 1;
                continue;
            }
            int right = 0;
            int down = 0;
            if (j > 0)
                right = curr[j - 1];
            if (i > 0)
                down = prev[j];
            curr[j] = right + down;
        }
        prev = curr;
    }
    return prev[n];
}
int main()
{
    int m = 3;
    int n = 2;
    cout << solve(m - 1, n - 1) << endl; // Recursion
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << solveMemo(m - 1, n - 1, dp) << endl; // Memoization
    cout << solveTab(m - 1, n - 1) << endl;      // Tabulation
    cout << solveSO(m - 1, n - 1) << endl;       // Space Optimized
    return 0;
}