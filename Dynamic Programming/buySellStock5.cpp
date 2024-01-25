#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Cooldown after a transaction and no buy or sell can be made on this day
int solve(int index, int buy, vector<int> &prices)
{
    int n = prices.size();
    if (index >= n)
    {
        return 0;
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[index] + solve(index + 1, 0, prices), solve(index + 1, 1, prices));
    }
    else
    {
        profit = max(prices[index] + solve(index + 2, 1, prices), solve(index + 1, 0, prices));
    }
    return profit;
}
int solveMemo(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (index >= n)
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
        profit = max(-prices[index] + solveMemo(index + 1, 0, prices, dp), solveMemo(index + 1, 1, prices, dp));
    }
    else
    {
        profit = max(prices[index] + solveMemo(index + 2, 1, prices, dp), solveMemo(index + 1, 0, prices, dp));
    }
    dp[index][buy] = profit;
    return dp[index][buy];
}
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(3, 0));
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
                profit = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(3, 0);
    vector<int> next(3, 0);
    vector<int> nextToNext(3, 0);
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
                profit = max(prices[index] + nextToNext[1], next[0]);
            }
            curr[buy] = profit;
        }
        nextToNext = next;
        next = curr;
    }
    return next[1];
}
int main()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(0);
    prices.push_back(2);
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << solve(0, 1, prices) << endl;         // Recursion
    cout << solveMemo(0, 1, prices, dp) << endl; // Memoization
    cout << solveTab(prices) << endl;            // Tabulation
    cout << solveSO(prices) << endl;             // Space Optimized
    return 0;
}