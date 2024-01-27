#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool solve(string s, string p, int i, int j)
{
    if (i < 0 and j < 0)
    {
        return true;
    }
    if (i >= 0 and j < 0)
    {
        return false;
    }
    if (i < 0 and j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (s[i] == p[j] or p[j] == '?')
    {
        return solve(s, p, i - 1, j - 1);
    }
    else if (p[j] == '*')
    {
        return solve(s, p, i - 1, j) or solve(s, p, i, j - 1);
    }
    else
    {
        return false;
    }
}
bool solveMemo(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
    {
        return true;
    }
    if (i > 0 and j == 0)
    {
        return false;
    }
    if (i == 0 and j > 0)
    {
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i - 1] == p[j - 1] or p[j - 1] == '?')
    {
        dp[i][j] = solveMemo(s, p, i - 1, j - 1, dp);
    }
    else if (p[j - 1] == '*')
    {
        dp[i][j] = solveMemo(s, p, i - 1, j, dp) or solveMemo(s, p, i, j - 1, dp);
    }
    else
    {
        dp[i][j] = false;
    }
    return dp[i][j];
}
int solveTab(string s, string p)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));
    dp[0][0] = 1;
    for (int j = 1; j <= p.length(); j++)
    {
        bool flag = 1;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = 0;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
            {
                int take = dp[i - 1][j];
                int notTake = dp[i][j - 1];
                dp[i][j] = (take || notTake);
            }
        }
    }
    return dp[s.length()][p.length()];
}
int solveSO(string s, string p)
{
    vector<int> prev(p.length() + 1, 0);
    vector<int> curr(p.length() + 1, 0);
    prev[0] = true;
    for (int j = 1; j <= p.length(); j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        curr[0] = 0;
        for (int j = 1; j <= p.length(); j++)
        {
            if (s[i - 1] == p[j - 1] or p[j - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                curr[j] = prev[j] or curr[j - 1];
            }
            else
            {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[p.length()];
}
int main()
{
    string s = "aa";
    string p = "*";
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    cout << (solve(s, p, s.length() - 1, p.length() - 1) ? "Matched" : "Don't Match") << endl;
    cout << (solveMemo(s, p, s.length(), p.length(), dp) ? "Matched" : "Don't Match") << endl;
    cout << (solveTab(s, p) ? "Matched" : "Don't Match") << endl;
    cout << (solveSO(s, p) ? "Matched" : "Don't Match") << endl;
    return 0;
}