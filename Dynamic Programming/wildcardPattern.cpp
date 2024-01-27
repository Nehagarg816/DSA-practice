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
int main()
{
    string s = "aa";
    string p = "?";
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    cout << (solve(s, p, s.length() - 1, p.length() - 1) ? "Matched" : "Don't Match") << endl;
    cout << (solveMemo(s, p, s.length(), p.length(), dp) ? "Matched" : "Don't Match") << endl;
    return 0;
}