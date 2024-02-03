#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Partition Array for Maximum Sum
int solve(vector<int> &arr, int k, int index)
{
    int n = arr.size();
    if (index >= n)
    {
        return 0;
    }
    int ans = 0;
    int maxi = 0;
    for (int i = index; i < min(index + k, n); i++)
    {
        maxi = max(maxi, arr[i]);
        ans = max(ans, (i - index + 1) * maxi + solve(arr, k, i + 1));
    }
    return ans;
}
int solveMemo(vector<int> &arr, int k, int index, vector<int> &dp)
{
    int n = arr.size();
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int ans = 0;
    int maxi = 0;
    for (int i = index; i < min(index + k, n); i++)
    {
        maxi = max(maxi, arr[i]);
        ans = max(ans, (i - index + 1) * maxi + solveMemo(arr, k, i + 1, dp));
    }
    dp[index] = ans;
    return dp[index];
}
int solveTab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        int ans = 0;
        int maxi = 0;
        for (int i = index; i < min(index + k, n); i++)
        {
            maxi = max(maxi, arr[i]);
            ans = max(ans, (i - index + 1) * maxi + dp[i + 1]);
        }
        dp[index] = ans;
    }
    return dp[0];
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(15);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(10);
    int k = 3;
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << solve(arr, k, 0) << endl;
    cout << solveMemo(arr, k, 0, dp) << endl;
    cout << solveTab(arr, k) << endl;
    return 0;
}