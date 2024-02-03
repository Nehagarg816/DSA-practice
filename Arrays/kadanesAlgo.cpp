#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Maximum Subarray Sum (Kadane's Algorithm)
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int maxi = nums[0];
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}