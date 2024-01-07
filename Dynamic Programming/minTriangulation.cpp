#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &values, int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, (values[i] * values[j] * values[k] + solve(values, i, k) + solve(values, k, j)));
    }
    return ans;
}
int solveMemo(vector<int> &values, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, (values[i] * values[j] * values[k] + solve(values, i, k) + solve(values, k, j)));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int solveTab(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, (values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}
int main()
{
    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(4);
    values.push_back(5);
    values.push_back(6);
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << solve(values, 0, n - 1) << endl;
    cout << solveMemo(values, 0, n - 1, dp) << endl;
    cout << solveTab(values) << endl;
    return 0;
}