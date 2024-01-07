#include <iostream>
#include <vector>
#include <bits\stdc++.h>
using namespace std;                      // Minimum Number of coins
int solve(vector<int> &coins, int target) // T.C - O(exponential)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, target - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int solveMemo(vector<int> &coins, int target, vector<int> &dp) // T.C - O(target*coins.size())
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        dp[i] = solve(coins, target - coins[i]);
        if (dp[i] != INT_MAX)
        {
            mini = min(mini, 1 + dp[i]);
        }
    }
    dp[target] = mini;
    return mini;
}
int solveTab(vector<int> &coins, int target) // T.C - O(target*coins.size())
{
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 and dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[target] == INT_MAX)
    {
        return -1;
    }
    return dp[target];
}
int main()
{
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(4);
    coins.push_back(10);
    int target = 19;
    vector<int> dp(target + 1, -1);
    cout << solve(coins, target) << endl;         // Recursion
    cout << solveMemo(coins, target, dp) << endl; // Recursion + Memoization
    cout << solveTab(coins, target);              // Tabulation
    return 0;
}