#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int index, int diff)
{
    int n = nums.size();
    if (index < 0)
    {
        return 0;
    }
    int ans = 0;
    if (index == n)
    {
        return 0;
    }
    for (int j = index - 1; j >= 0; j--)
    {
        if (nums[index] - nums[j] == diff)
        {
            ans = max(ans, 1 + solve(nums, j, diff));
        }
    }
    return ans;
}
int solve2(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
    {
        return n;
    }
    int ans = 0;
    unordered_map<int, unordered_map<int, int>> dp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            int cnt = 1;
            if (dp[j].count(diff))
            {
                cnt = dp[j][diff];
            }
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, 2 + solve(nums, i, nums[j] - nums[i]));
        }
    }
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(10);
    nums.push_back(13);
    nums.push_back(14);
    nums.push_back(19);
    cout << longestArithSeqLength(nums) << endl; // Recursion
    cout << solve2(nums) << endl;                // Tabulation
    return 0;
}