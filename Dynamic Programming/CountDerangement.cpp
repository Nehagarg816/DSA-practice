#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int solve(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    int ans = (n - 1) % MOD * (solve(n - 1) % MOD + solve(n - 2) % MOD) % MOD;
    return ans;
}
int solveMemo(int n, vector<int> dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = (n - 1) % MOD * (solveMemo(n - 1, dp) % MOD + solveMemo(n - 2, dp) % MOD) % MOD;
    dp[n] = ans;
    return dp[n];
}
int solveTab(int n)
{
    vector<int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        int first = dp[i - 1] % MOD;
        int second = dp[i - 2] % MOD;
        int sum = (first + second) % MOD;
        dp[i] = ((i - 1) % MOD) * sum;
    }
    return dp[n];
}
int solveSpace(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 3; i <= n; i++)
    {
        int first = prev1 % MOD;
        int second = prev2 % MOD;
        int sum = (first + second) % MOD;
        int ans = ((i - 1) * sum) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << solve(n) << endl;         // Recursion
    cout << solveMemo(n, dp) << endl; // Recursion + Memoization
    cout << solveTab(n) << endl;      // Tabulation
    cout << solveSpace(n);            // Space Optimization
    return 0;
}