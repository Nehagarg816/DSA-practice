#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Minimum cost Tree from leaf nodes
int solve(vector<int> &arr, map<pair<int, int>, int> &m, int left, int right)
{
    if (left == right)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, ((m[{left, i}] * m[{i + 1, right}]) + solve(arr, m, left, i) + solve(arr, m, i + 1, right)));
    }
    return ans;
}
int solveMemo(vector<int> &arr, map<pair<int, int>, int> &m, int left, int right, vector<vector<int>> &dp)
{
    if (left == right)
    {
        return 0;
    }
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }
    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, ((m[{left, i}] * m[{i + 1, right}]) + solveMemo(arr, m, left, i, dp) + solveMemo(arr, m, i + 1, right, dp)));
    }
    dp[left][right] = ans;
    return dp[left][right];
}
int solveTab(vector<int> &arr, map<pair<int, int>, int> &m)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int left = n - 1; left >= 0; left--)
    {
        for (int right = 0; right < n; right++)
        {
            int ans = INT_MAX;
            if (left == right)
            {
                continue;
            }
            for (int i = left; i < right; i++)
            {
                ans = min(ans, ((m[{left, i}] * m[{i + 1, right}]) + dp[left][i] + dp[i + 1][right]));
            }
            dp[left][right] = ans;
        }
    }
    return dp[0][n - 1];
}
void minCost(vector<int> &arr)
{
    map<pair<int, int>, int> m;
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        m[{i, i}] = arr[i];
        for (int j = i; j < n; j++)
        {
            m[{i, j}] = max(arr[j], m[{i, j - 1}]);
        }
    }
    cout << solve(arr, m, 0, n - 1) << endl;         // Recursion
    cout << solveMemo(arr, m, 0, n - 1, dp) << endl; // Recursion + Memoization
    cout << solveTab(arr, m) << endl;                // Tabulation
}
int main()
{
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(4);
    minCost(arr);
    return 0;
}