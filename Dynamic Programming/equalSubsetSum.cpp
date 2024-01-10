#include <iostream>
#include <vector>
#include <bits\stdc++.h>
using namespace std; // Partition Equal Subset Sum
bool solve(int index, vector<int> &nums, int target)
{
    int n = nums.size();
    if (index >= n)
    {
        return 0;
    }
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    int incl = solve(index + 1, nums, target - nums[index]);
    int excl = solve(index + 1, nums, target);
    return incl or excl;
}
bool solveMemo(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (index >= n)
    {
        return 0;
    }
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    int incl = solveMemo(index + 1, nums, target - nums[index], dp);
    int excl = solveMemo(index + 1, nums, target, dp);
    dp[index][target] = incl or excl;
    return dp[index][target];
}
bool solveTab(vector<int> &nums, int total)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(total + 1, 0));
    int n = nums.size();
    for (int i = 0; i < nums.size() + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 0; t <= total / 2; t++)
        {
            bool incl = 0;
            if (t - nums[index] >= 0)
            {
                incl = dp[index + 1][t - nums[index]];
            }
            bool excl = dp[index + 1][t];
            dp[index][t] = incl or excl;
        }
    }
    return dp[0][total / 2];
}
bool solveSO(vector<int> &nums, int total)
{
    vector<int> curr(total / 2 + 1);
    vector<int> next(total / 2 + 1);
    int n = nums.size();
    next[0] = 1;
    curr[0] = 1;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 0; t <= total / 2; t++)
        {
            bool incl = 0;
            if (t - nums[index] >= 0)
            {
                incl = next[t - nums[index]];
            }
            bool excl = next[t];
            curr[t] = incl or excl;
        }
        next = curr;
    }
    return next[total / 2];
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(11);
    nums.push_back(5);
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        total += nums[i];
    }
    if (total % 2 != 0)
    {
        cout << "false";
        return 0;
    }
    int target = total / 2;
    if (solve(0, nums, target))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    } // Recursion
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    if (solveMemo(0, nums, target, dp))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    } // Recursion + Memoization
    if (solveTab(nums, total))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    } // Tabulation
    if (solveSO(nums, total))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    } // Space Optimisation
    return 0;
}