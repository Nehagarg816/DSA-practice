#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Longest Arithmetic Subsequence with given common difference
int solve(vector<int> &nums, int d)
{
    unordered_map<int, int> dp;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = nums[i] - d;
        int tempAns = 0;
        if (dp.count(temp))
        {
            tempAns = dp[temp];
        }
        dp[nums[i]] = 1 + tempAns;
        ans = max(ans, dp[nums[i]]);
    }
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(1);
    int d = -2;
    cout << solve(nums, d);
    return 0;
}