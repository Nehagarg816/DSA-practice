#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &satisfaction, int index, int time)
{
    int n = satisfaction.size();
    if (index == n)
    {
        return 0;
    }
    int incl = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);
    int excl = 0 + solve(satisfaction, index + 1, time);
    return max(incl, excl);
}
int solveMemo(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
{
    int n = satisfaction.size();
    if (index == n)
    {
        return 0;
    }
    if (dp[index][time] != -1)
    {
        return dp[index][time];
    }
    int incl = satisfaction[index] * (time + 1) + solveMemo(satisfaction, index + 1, time + 1, dp);
    int excl = 0 + solveMemo(satisfaction, index + 1, time, dp);
    dp[index][time] = max(incl, excl);
    return dp[index][time];
}
int solveTab(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int incl = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int excl = 0 + dp[index + 1][time];
            dp[index][time] = max(incl, excl);
        }
    }
    return dp[0][0];
}
int solveSO(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int incl = satisfaction[index] * (time + 1) + next[time + 1];
            int excl = 0 + next[time];
            curr[time] = max(incl, excl);
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    vector<int> satisfaction;
    satisfaction.push_back(4);
    satisfaction.push_back(3);
    satisfaction.push_back(2);
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    sort(satisfaction.begin(), satisfaction.end());
    cout << solve(satisfaction, 0, 0) << endl;
    cout << solveMemo(satisfaction, 0, 0, dp) << endl;
    cout << solveTab(satisfaction) << endl;
    cout << solveSO(satisfaction) << endl;
    return 0;
}