#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        nums[i] = max(nums[i] + i, nums[i - 1]);
    }
    int index = 0;
    int ans = 0;
    while (index < n - 1)
    {
        ans++;
        index = nums[index];
    }
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(4);
    cout << jump(nums) << endl;
    return 0;
}