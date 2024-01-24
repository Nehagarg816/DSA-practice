#include <iostream>
#include <bits/stdc++.h>
using namespace std; // At most k transactions
int solve(int index, int operationNo, vector<int> &prices, int k)
{
    int n = prices.size();
    if (index == n)
    {
        return 0;
    }
    if (operationNo == 2 * k)
    {
        return 0;
    }
    int profit = 0;
    if (operationNo % 2 == 0)
    {
        profit = max(-prices[index] + solve(index + 1, operationNo + 1, prices, k), solve(index + 1, operationNo, prices, k));
    }
    else
    {
        profit = max(prices[index] + solve(index + 1, operationNo + 1, prices, k), solve(index + 1, operationNo, prices, k));
    }
    return profit;
}
int solveMemo(int index, int operationNo, vector<int> &prices, int k, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (index == n)
    {
        return 0;
    }
    if (operationNo == 2 * k)
    {
        return 0;
    }
    if (dp[index][operationNo] != -1)
    {
        return dp[index][operationNo];
    }
    int profit = 0;
    if (operationNo % 2 == 0)
    {
        profit = max(-prices[index] + solveMemo(index + 1, operationNo + 1, prices, k, dp), solveMemo(index + 1, operationNo, prices, k, dp));
    }
    else
    {
        profit = max(prices[index] + solveMemo(index + 1, operationNo + 1, prices, k, dp), solveMemo(index + 1, operationNo, prices, k, dp));
    }
    dp[index][operationNo] = profit;
    return dp[index][operationNo];
}
int solveTab(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
        {
            int profit = 0;
            if (operationNo % 2 == 0)
            {
                profit = max(-prices[index] + dp[index + 1][operationNo + 1], dp[index + 1][operationNo]);
            }
            else
            {
                profit = max(prices[index] + dp[index + 1][operationNo + 1], dp[index + 1][operationNo]);
            }
            dp[index][operationNo] = profit;
        }
    }
    return dp[0][0];
}
int solveSO(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
        {
            int profit = 0;
            if (operationNo % 2 == 0)
            {
                profit = max(-prices[index] + next[operationNo + 1], next[operationNo]);
            }
            else
            {
                profit = max(prices[index] + next[operationNo + 1], next[operationNo]);
            }
            curr[operationNo] = profit;
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(4);
    prices.push_back(1);
    int k = 2;
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k, -1));
    cout << solve(0, 0, prices, k) << endl;         // Recursion
    cout << solveMemo(0, 0, prices, k, dp) << endl; // Memoization
    cout << solveTab(prices, k) << endl;            // Tabulation
    cout << solveSO(prices, k) << endl;             // Space Optimized
    return 0;
}