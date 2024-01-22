#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Longest Common Subsequence
int solve(int m, int n, string text1, string text2)
{
    if (m == 0 or n == 0)
    {
        return 0;
    }
    int ans = 0;
    if (text1[m - 1] == text2[n - 1])
    {
        ans = 1 + solve(m - 1, n - 1, text1, text2);
    }
    else
    {
        ans = max(solve(m - 1, n, text1, text2), solve(m, n - 1, text1, text2));
    }
    return ans;
}
int solveMemo(int m, int n, string text1, string text2, vector<vector<int>> &dp)
{
    if (m == 0 or n == 0)
    {
        return 0;
    }
    if (dp[m - 1][n - 1] != -1)
    {
        return dp[m - 1][n - 1];
    }
    int ans = 0;
    if (text1[m - 1] == text2[n - 1])
    {
        ans = 1 + solveMemo(m - 1, n - 1, text1, text2, dp);
    }
    else
    {
        ans = max(solveMemo(m - 1, n, text1, text2, dp), solveMemo(m, n - 1, text1, text2, dp));
    }
    dp[m - 1][n - 1] = ans;
    return dp[m - 1][n - 1];
}
int solveTab(int m, int n, string text1, string text2)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ans = 0;
            if (text1[i - 1] == text2[j - 1])
            {
                ans = 1 + dp[i - 1][j - 1];
            }
            else
            {
                ans = max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[m][n];
}
int solveSO(int m, int n, string text1, string text2)
{
    vector<int> curr(n + 1, 0);
    vector<int> prev(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ans = 0;
            if (text1[i - 1] == text2[j - 1])
            {
                ans = 1 + prev[j - 1];
            }
            else
            {
                ans = max(prev[j], curr[j - 1]);
            }
            curr[j] = ans;
        }
        prev = curr;
    }
    return prev[n];
}
int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << solve(m, n, text1, text2) << endl;
    cout << solveMemo(m, n, text1, text2, dp) << endl;
    cout << solveTab(m, n, text1, text2) << endl;
    cout << solveSO(m, n, text1, text2) << endl;
    return 0;
}