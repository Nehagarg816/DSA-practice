#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Out of Boundary Paths
const int mod = 1e9 + 7;
int solve(int m, int n, int maxi, int i, int j)
{
    if (i == m or i < 0 or j < 0 or j == n)
    {
        return 1;
    }
    if (maxi == 0)
    {
        return 0;
    }
    int top = 0, down = 0, lft = 0, rgt = 0;
    top = solve(m, n, maxi - 1, i - 1, j) % mod;
    down = solve(m, n, maxi - 1, i + 1, j) % mod;
    lft = solve(m, n, maxi - 1, i, j - 1) % mod;
    rgt = solve(m, n, maxi - 1, i, j + 1) % mod;
    long long ans = (((top + down) % mod + lft) % mod + rgt) % mod;
    return ans % mod;
}
int solveMemo(int m, int n, int maxi, int i, int j, vector<vector<vector<int>>> &dp)
{
    if (i == m or i < 0 or j < 0 or j == n)
    {
        return 1;
    }
    if (maxi == 0)
    {
        return 0;
    }
    if (dp[i][j][maxi] != -1)
    {
        return dp[i][j][maxi];
    }
    int top = 0, down = 0, lft = 0, rgt = 0;
    top = solveMemo(m, n, maxi - 1, i - 1, j, dp) % mod;
    down = solveMemo(m, n, maxi - 1, i + 1, j, dp) % mod;
    lft = solveMemo(m, n, maxi - 1, i, j - 1, dp) % mod;
    rgt = solveMemo(m, n, maxi - 1, i, j + 1, dp) % mod;
    long long ans = (((top + down) % mod + lft) % mod + rgt) % mod;
    dp[i][j][maxi] = ans % mod;
    return dp[i][j][maxi] % mod;
}
int main()
{
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0, startColumn = 0;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
    cout << solve(m, n, maxMove, startRow, startColumn) << endl;         // Recursion
    cout << solveMemo(m, n, maxMove, startRow, startColumn, dp) << endl; // Memoization
    return 0;
}