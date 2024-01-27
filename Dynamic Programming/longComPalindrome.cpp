#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(string &s, string &r, int i, int j)
{
    if (i == s.length())
    {
        return 0;
    }
    if (j == r.length())
    {
        return 0;
    }
    int ans = 0;
    // match
    if (s[i] == r[j])
    {
        ans = 1 + solve(s, r, i + 1, j + 1);
    }
    else
    {
        ans = max(solve(s, r, i + 1, j), solve(s, r, i, j + 1));
    }
    return ans;
}
int solveMemo(string &s, string &r, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.length())
    {
        return 0;
    }
    if (j == r.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    // match
    if (s[i] == r[j])
    {
        ans = 1 + solveMemo(s, r, i + 1, j + 1, dp);
    }
    else
    {
        ans = max(solveMemo(s, r, i + 1, j, dp), solveMemo(s, r, i, j + 1, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int solveTab(string s, string r)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(r.length() + 1, 0));
    for (int i = s.length() - 1; i >= 0; i--)
    {
        for (int j = r.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            // match
            if (s[i] == r[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveSO(string s, string r)
{
    vector<int> curr(r.length() + 1, 0);
    vector<int> next(r.length() + 1, 0);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        for (int j = r.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            // match
            if (s[i] == r[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
void longestPalindromeSubseq(string s)
{
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    vector<vector<int>> dp(s.length(), vector<int>(revStr.length(), -1));
    cout << solve(s, revStr, 0, 0) << endl;         // Recursion
    cout << solveMemo(s, revStr, 0, 0, dp) << endl; // Recursion + Memoization
    cout << solveTab(s, revStr) << endl;            // Tabulation
    cout << solveSO(s, revStr) << endl;             // Space Optimized
}
int main()
{
    string s = "bbbab";
    longestPalindromeSubseq(s);
    return 0;
}