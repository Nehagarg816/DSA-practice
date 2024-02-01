#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool solve(string s1, string s2, string s3, int i, int j, int k)
{
    if (k == 0)
    {
        return (i == 0 and j == 0);
    }
    bool ans = false;
    if (i > 0 and s1[i - 1] == s3[k - 1])
    {
        ans = ans or solve(s1, s2, s3, i - 1, j, k - 1);
    }
    if (j > 0 and s2[j - 1] == s3[k - 1])
    {
        ans = ans or solve(s1, s2, s3, i, j - 1, k - 1);
    }
    return ans;
}
bool solveMemo(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return (i == 0 and j == 0);
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    bool ans = false;
    if (i > 0 and s1[i - 1] == s3[k - 1])
    {
        ans = ans or solveMemo(s1, s2, s3, i - 1, j, k - 1, dp);
    }
    if (j > 0 and s2[j - 1] == s3[k - 1])
    {
        ans = ans or solveMemo(s1, s2, s3, i, j - 1, k - 1, dp);
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int solveTab(string s1, string s2, string s3)
{
    int n = s1.length();
    int m = s2.length();
    int o = s3.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                if (s2[j - 1] == s3[j - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
            else if (j == 0)
            {
                if (s1[i - 1] == s3[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else
            {
                if (s1[i - 1] == s3[i + j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    int res = dp[n][m];
    return res;
}
void isInterleave(string s1, string s2, string s3)
{
    int n = s1.length();
    int m = s2.length();
    int o = s3.length();
    if (m + n != o)
    {
        cout << "false";
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << solve(s1, s2, s3, n, m, o) << endl;         // Recursion
    cout << solveMemo(s1, s2, s3, n, m, o, dp) << endl; // Recursion + Memoization
    cout << solveTab(s1, s2, s3) << endl;               // Tabulation
}
int main()
{
    string s1 = "aa";
    string s2 = "b";
    string s3 = "aba";
    isInterleave(s1, s2, s3);
    return 0;
}