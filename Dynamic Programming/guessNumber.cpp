#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    int maxi = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        maxi = min(maxi, i + max(solve(n, start, i - 1), solve(n, i + 1, end)));
    }
    return maxi;
}
int solveMemo(int n, int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int maxi = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        maxi = min(maxi, i + max(solveMemo(n, start, i - 1, dp), solveMemo(n, i + 1, end, dp)));
    }
    dp[start][end] = maxi;
    return dp[start][end];
}
int solveTab(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int start = n; start >= 1; start--)
    {
        for (int end = start; end <= n; end++)
        {
            if (start == end)
            {
                continue;
            }
            int maxi = INT_MAX;
            for (int i = start; i <= end; i++)
            {
                maxi = min(maxi, i + max(dp[start][i - 1], dp[i + 1][end]));
            }
            dp[start][end] = maxi;
        }
    }
    return dp[1][n];
}
int main()
{
    int n = 4;
    int start = 1;
    int end = n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << solve(n, start, end) << endl;         // Recursion
    cout << solveMemo(n, start, end, dp) << endl; // Recursion + Memoization
    cout << solveTab(n) << endl;                  // Tabulation
    return 0;
}