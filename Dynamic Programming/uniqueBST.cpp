#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Unique Binary Search Tree
int solve(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i - 1) * solve(n - i);
    }
    return ans;
}
int solveMemo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solveMemo(i - 1, dp) * solveMemo(n - i, dp);
    }
    dp[n] = ans;
    return dp[n];
}
int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
int main()
{
    int n = 4;
    vector<int> dp(n + 1, -1);
    cout << solve(n) << endl;         // Recursion
    cout << solveMemo(n, dp) << endl; // Recursion + Memoization
    cout << solveTab(n) << endl;      // Tabulation
    return 0;
}