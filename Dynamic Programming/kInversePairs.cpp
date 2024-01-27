#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int solve(int n, int k)
{
    if (n == 0 and k == 0)
    {
        return 1;
    }
    if (k < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int x = 0; x <= min(n - 1, k); x++)
    {
        if (k - x >= 0)
            ans += solve(n - 1, k - x) % MOD;
    }
    return ans % MOD;
}
int solveMemo(int n, int k, vector<vector<int>> &dp)
{
    if (k <= 0)
    {
        return !k;
    }
    if (n <= 0)
    {
        return (k == 0) ? 1 : 0;
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    dp[n][k] = (solveMemo(n - 1, k, dp) + solveMemo(n, k - 1, dp)) % MOD;
    return dp[n][k] = (dp[n][k] - solveMemo(n - 1, k - n, dp) + MOD) % MOD;
}
int solveTab(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int x = 0; x <= min(j, i - 1); x++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            }
        }
    }
    return dp[n][k];
}
int main()
{
    int n = 1000;
    int k = 1000;
    vector<vector<int>> dp(1001, vector<int>(1001, -1));
    // cout << solve(n, k) << endl;
    cout << solveMemo(n, k, dp) << endl;
    cout << solveTab(n, k) << endl;
    return 0;
}