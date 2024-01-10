#include <iostream>
#include <vector>
#include <bits\stdc++.h>
using namespace std;
int solve(vector<int> &arr1, vector<int> &arr2, int index, bool swapped)
{
    int n = arr1.size();
    if (index == n)
    {
        return 0;
    }
    int ans = INT_MAX;
    int prev1 = arr1[index - 1];
    int prev2 = arr2[index - 1];
    if (swapped)
    {
        swap(prev1, prev2);
    }
    // noswap
    if (arr1[index] > prev1 and arr2[index] > prev2)
    {
        ans = solve(arr1, arr2, index + 1, 0);
    }
    // swap
    if (arr1[index] > prev2 and arr2[index] > prev1)
    {
        ans = min(ans, 1 + solve(arr1, arr2, index + 1, 1));
    }
    return ans;
}
int main()
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums1.push_back(5);
    nums1.push_back(4);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(7);
    int n = nums1.size();
    vector<int> arr1(n + 1, -1);
    vector<int> arr2(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        arr1[i] = nums1[i - 1];
        arr2[i] = nums2[i - 1];
    }
    bool swapped = 0;
    cout << solve(arr1, arr2, 1, swapped) << endl; // Recursion
    return 0;
}