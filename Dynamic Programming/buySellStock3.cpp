#include <iostream>
#include <bits/stdc++.h>
using namespace std; // At most 2 transactions
int solve(int index, int buy, int limit, vector<int> &prices)
{
    int n = prices.size();
    if (index == n)
    {
        return 0;
    }
    if (limit == 0)
    {
        return 0;
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[index] + solve(index + 1, 0, limit, prices), solve(index + 1, 1, limit, prices));
    }
    else
    {
        profit = max(prices[index] + solve(index + 1, 1, limit - 1, prices), solve(index + 1, 0, limit, prices));
    }
    return profit;
}
int solveMemo(int index, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    if (index == n)
    {
        return 0;
    }
    if (limit == 0)
    {
        return 0;
    }
    if (dp[index][buy][limit] != -1)
    {
        return dp[index][buy][limit];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[index] + solveMemo(index + 1, 0, limit, prices, dp), solveMemo(index + 1, 1, limit, prices, dp));
    }
    else
    {
        profit = max(prices[index] + solveMemo(index + 1, 1, limit - 1, prices, dp), solveMemo(index + 1, 0, limit, prices, dp));
    }
    dp[index][buy][limit] = profit;
    return dp[index][buy][limit];
}
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[index] + dp[index + 1][0][limit], dp[index + 1][1][limit]);
                }
                else
                {
                    profit = max(prices[index] + dp[index + 1][1][limit - 1], dp[index + 1][0][limit]);
                }
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[index] + next[0][limit], next[1][limit]);
                }
                else
                {
                    profit = max(prices[index] + next[1][limit - 1], next[0][limit]);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}
int main()
{
    vector<int> prices;
    prices.push_back(3);
    prices.push_back(3);
    prices.push_back(5);
    prices.push_back(0);
    prices.push_back(0);
    prices.push_back(3);
    prices.push_back(1);
    prices.push_back(4);
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    cout << solve(0, 1, 2, prices) << endl;         // Recursion
    cout << solveMemo(0, 1, 2, prices, dp) << endl; // Memoization
    cout << solveTab(prices) << endl;               // Tabulation
    cout << solveSO(prices) << endl;                // Space Optimized
    return 0;
}