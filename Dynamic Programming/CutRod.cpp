#include <iostream>
#include <bits\stdc++.h>
using namespace std; // Cut Rod into segments of X,Y,Z
int solve(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;
    int ans = max(a, max(b, c));
    if (ans == INT_MIN)
    {
        return 0;
    }
    return ans;
}
int solveMemo(int n, int x, int y, int z, vector<int> dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;
    dp[n] = max(a, max(b, c));
    if (dp[n] < INT_MIN)
    {
        return 0;
    }
    return dp[n];
}
int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0 and dp[i - x] != -1)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0 and dp[i - y] != -1)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0 and dp[i - z] != -1)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    if (dp[n] == -1)
    {
        return 0;
    }
    return dp[n];
}
int solveTab2(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    if (dp[n] == INT_MIN)
    {
        return 0;
    }
    return dp[n];
}
int main()
{
    int x = 5;
    int y = 2;
    int z = 2;
    int n = 7;
    vector<int> dp(n + 1, -1);
    cout << solve(n, x, y, z) << endl;         // Recursion
    cout << solveMemo(n, x, y, z, dp) << endl; // Recursion + Memoization
    cout << solveTab(n, x, y, z) << endl;      // Tabulation
    cout << solveTab2(n, x, y, z) << endl;     // Tabulation
    // Space optimization is not possible
    return 0;
}