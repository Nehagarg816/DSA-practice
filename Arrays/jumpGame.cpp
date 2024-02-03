#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int maxi = nums[0];
    int n = nums.size();
    if (n == 1)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (maxi >= n - 1)
        {
            return true;
        }
        if (nums[i] == 0 and maxi == i)
        {
            return false;
        }
        if (i + nums[i] > maxi)
        {
            maxi = i + nums[i];
        }
    }
    return true;
}
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(4);
    cout << canJump(nums);
    return 0;
}