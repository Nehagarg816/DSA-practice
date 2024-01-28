#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subarrays(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> sub(nums.begin() + i, nums.begin() + j + 1);
            ans.push_back(sub);
        }
    }
    return ans;
}
int maxProduct(vector<int> &nums)
{
    vector<vector<int>> sub = subarrays(nums);
    int ans = INT_MIN;
    for (int i = 0; i < sub.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < sub[i].size(); j++)
        {
            product *= sub[i][j];
        }
        ans = max(ans, product);
    }
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);
    cout << maxProduct(nums);
    return 0;
}