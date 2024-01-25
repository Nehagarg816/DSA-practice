#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int index, int buy, vector<int> &prices, int fees)
{
    int n = prices.size();
    if (index == n)
    {
        return 0;
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[index] + solve(index + 1, 0, prices, fees), solve(index + 1, 1, prices, fees));
    }
    else
    {
        profit = max(prices[index] - fees + solve(index + 1, 1, prices, fees), solve(index + 1, 0, prices, fees));
    }
    return profit;
}
int solveMemo(int index, int buy, vector<int> &prices, int fees, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (index == n)
    {
        return 0;
    }
    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[index] + solveMemo(index + 1, 0, prices, fees, dp), solveMemo(index + 1, 1, prices, fees, dp));
    }
    else
    {
        profit = max(prices[index] - fees + solveMemo(index + 1, 1, prices, fees, dp), solveMemo(index + 1, 0, prices, fees, dp));
    }
    dp[index][buy] = profit;
    return dp[index][buy];
}
int solveTab(vector<int> &prices, int fees)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
            }
            else
            {
                profit = max(prices[index] - fees + dp[index + 1][1], dp[index + 1][0]);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}
int solveSO(vector<int> &prices, int fees)
{
    int n = prices.size();
    vector<int> curr(3, 0);
    vector<int> next(3, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[index] + next[0], next[1]);
            }
            else
            {
                profit = max(prices[index] - fees + next[1], next[0]);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}
int main()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(8);
    prices.push_back(4);
    prices.push_back(9);
    int fees = 2;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << solve(0, 1, prices, fees) << endl;         // Recursion
    cout << solveMemo(0, 1, prices, fees, dp) << endl; // Recursion + Memoization
    cout << solveTab(prices, fees) << endl;            // Tabulation
    cout << solveSO(prices, fees) << endl;             // Space Optimized
    return 0;
}