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
int solveMemo(vector<int> &arr1, vector<int> &arr2, int index, bool swapped, vector<vector<int>> &dp)
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
    if (dp[index][swapped] != -1)
    {
        return dp[index][swapped];
    }
    // noswap
    if (arr1[index] > prev1 and arr2[index] > prev2)
    {
        ans = solveMemo(arr1, arr2, index + 1, 0, dp);
    }
    // swap
    if (arr1[index] > prev2 and arr2[index] > prev1)
    {
        ans = min(ans, 1 + solveMemo(arr1, arr2, index + 1, 1, dp));
    }
    dp[index][swapped] = ans;
    return dp[index][swapped];
}
int solveTab(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
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
                ans = dp[index + 1][0];
            }
            // swap
            if (arr1[index] > prev2 and arr2[index] > prev1)
            {
                ans = min(ans, 1 + dp[index + 1][1]);
            }
            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}
int solveSO(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int swap = 0;
    int noswap = 0;
    int currNoSwap = 0;
    int currSwap = 0;
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;
            int prev1 = arr1[index - 1];
            int prev2 = arr2[index - 1];
            if (swapped)
            {
                int temp = prev1;
                prev1 = prev2;
                prev2 = temp;
            }
            // noswap
            if (arr1[index] > prev1 and arr2[index] > prev2)
            {
                ans = noswap;
            }
            // swap
            if (arr1[index] > prev2 and arr2[index] > prev1)
            {
                ans = min(ans, 1 + swap);
            }
            if (swapped)
            {
                currSwap = ans;
            }
            else
            {
                currNoSwap = ans;
            }
        }
        swap = currSwap;
        noswap = currNoSwap;
    }
    return min(swap, noswap);
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
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    bool swapped = 0;
    cout << solve(nums1, nums2, 1, swapped) << endl;         // Recursion
    cout << solveMemo(nums1, nums2, 1, swapped, dp) << endl; // Recursion + Memoization
    cout << solveTab(nums1, nums2) << endl;                  // Tabulation
    cout << solveSO(nums1, nums2);                           // Space Optimization
    return 0;
}