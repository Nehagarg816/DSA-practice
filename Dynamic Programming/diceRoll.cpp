#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Number of Dices Rolls with target Sum
int solve(int dices, int faces, int target)
{
    if (target < 0)
    {
        return 0;
    }
    if (target == 0 and dices != 0)
    {
        return 0;
    }
    if (target != 0 and dices == 0)
    {
        return 0;
    }
    if (target == 0 and dices == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans += solve(dices - 1, faces, target - i);
    }
    return ans;
}
int solveMemo(int dices, int faces, int target, vector<vector<int>> &dp)
{
    if (target < 0)
    {
        return 0;
    }
    if (target == 0 and dices != 0)
    {
        return 0;
    }
    if (target != 0 and dices == 0)
    {
        return 0;
    }
    if (target == 0 and dices == 0)
    {
        return 1;
    }
    if (dp[dices][target] != -1)
    {
        return dp[dices][target];
    }
    int ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans += solveMemo(dices - 1, faces, target - i, dp);
    }
    dp[dices][target] = ans;
    return dp[dices][target];
}
int solveTab(int dices, int faces, int target)
{
    vector<vector<int>> dp(dices + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int dice = 1; dice <= dices; dice++)
    {
        for (int t = 1; t <= target; t++)
        {
            int ans = 0;
            for (int i = 1; i <= faces; i++)
            {
                if (t - i >= 0)
                    ans += dp[dice - 1][t - i];
            }
            dp[dice][t] = ans;
        }
    }
    return dp[dices][target];
}
int solveSO(int dices, int faces, int target)
{
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);
    prev[0] = 1;
    for (int dice = 1; dice <= dices; dice++)
    {
        for (int t = 1; t <= target; t++)
        {
            int ans = 0;
            for (int i = 1; i <= faces; i++)
            {
                if (t - i >= 0)
                    ans += prev[t - i];
            }
            curr[t] = ans;
        }
        prev = curr;
    }
    return prev[target];
}
int main()
{
    int n = 3;
    int k = 6;
    int target = 12;
    cout << solve(n, k, target) << endl; // Recursion
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    cout << solveMemo(n, k, target, dp) << endl; // Recursion + Memoization
    cout << solveTab(n, k, target) << endl;      // Tabulation
    cout << solveSO(n, k, target) << endl;       // Space Optimization
    return 0;
}