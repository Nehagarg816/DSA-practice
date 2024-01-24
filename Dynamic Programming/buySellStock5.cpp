#include <iostream>
#include <bits/stdc++.h>
using namespace std;
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
    return 0;
}