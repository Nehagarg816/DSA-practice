#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solve(n - i * i));
    }
    return ans;
}
int solveMemo(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveMemo(n - i * i, dp));
    }
    dp[n] = ans;
    return dp[n];
}
int solveTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
    }
    return dp[n];
}
int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << solve(n) << endl;
    cout << solveMemo(n, dp) << endl;
    cout << solveTab(n) << endl;
    return 0;
}