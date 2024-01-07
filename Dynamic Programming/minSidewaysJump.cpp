#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &obstacles, int currlane, int currpos)
{
    int n = obstacles.size() - 1;
    if (currpos == n)
    {
        return 0;
    }
    if (obstacles[currpos + 1] != currlane)
    {
        return solve(obstacles, currlane, currpos + 1);
    }
    else
    {
        int jump = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i and obstacles[currpos] != i)
            {
                jump = min(jump, 1 + solve(obstacles, i, currpos));
            }
        }
        return jump;
    }
}
int solveMemo(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp)
{
    int n = obstacles.size() - 1;
    if (currpos == n)
    {
        return 0;
    }
    if (dp[currlane][currpos] != -1)
    {
        return dp[currlane][currpos];
    }
    if (obstacles[currpos + 1] != currlane)
    {
        return solveMemo(obstacles, currlane, currpos + 1, dp);
    }
    else
    {
        int jump = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i and obstacles[currpos] != i)
            {
                jump = min(jump, 1 + solveMemo(obstacles, i, currpos, dp));
            }
        }
        dp[currlane][currpos] = jump;
    }
    return dp[currlane][currpos];
}
int solveTab(vector<int> obstacles)
{
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;
    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (obstacles[currpos + 1] != currlane)
            {
                dp[currlane][currpos] = dp[currlane][currpos + 1];
            }
            else
            {
                int jump = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currlane != i and obstacles[currpos] != i)
                    {
                        jump = min(jump, 1 + dp[i][currpos + 1]);
                    }
                }
                dp[currlane][currpos] = jump;
            }
        }
    }
    return min({dp[2][0], 1 + dp[1][0], 1 + dp[3][0]});
}
int solveSO(vector<int> obstacles)
{
    int n = obstacles.size() - 1;
    // vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);
    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;
    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (obstacles[currpos + 1] != currlane)
            {
                curr[currlane] = next[currlane];
            }
            else
            {
                int jump = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currlane != i and obstacles[currpos] != i)
                    {
                        jump = min(jump, 1 + next[i]);
                    }
                }
                curr[currlane] = jump;
            }
        }
        next = curr;
    }
    return min({next[2], 1 + next[1], 1 + next[3]});
}
int main()
{
    vector<int> obstacles;
    obstacles.push_back(0);
    obstacles.push_back(1);
    obstacles.push_back(2);
    obstacles.push_back(3);
    obstacles.push_back(0);
    vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
    cout << solve(obstacles, 2, 0) << endl;         // Recursive solution
    cout << solveMemo(obstacles, 2, 0, dp) << endl; // Recursion + Memoization
    cout << solveTab(obstacles) << endl;            // Tabulation
    cout << solveSO(obstacles) << endl;             // space Optimisation
    return 0;
}