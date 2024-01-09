#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int solve(int index, int endIndex, vector<int> &slices, int n)
{
    // Base case
    if (n == 0 or index > endIndex)
    {
        return 0;
    }
    // you eat slice
    int incl = slices[index] + solve(index + 2, endIndex, slices, n - 1);
    // you dont eat slice
    int excl = 0 + solve(index + 1, endIndex, slices, n);
    return max(incl, excl);
}
int solveMemo(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
{
    // Base case
    if (n == 0 or index > endIndex)
    {
        return 0;
    }
    if (dp[index][n] != -1)
    {
        return dp[index][n];
    }
    // you eat slice
    int incl = slices[index] + solveMemo(index + 2, endIndex, slices, n - 1, dp);
    // you dont eat slice
    int excl = 0 + solveMemo(index + 1, endIndex, slices, n, dp);
    dp[index][n] = max(incl, excl);
    return dp[index][n];
}
int solveTab(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));
    // for the case from 0 to k-2
    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= (k / 3); n++)
        {
            // you eat slice
            int incl = slices[index] + dp1[index + 2][n - 1];
            // you dont eat slice
            int excl = 0 + dp1[index + 1][n];
            dp1[index][n] = max(incl, excl);
        }
    }
    int case1 = dp1[0][k / 3];
    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= (k / 3); n++)
        {
            // you eat slice
            int incl = slices[index] + dp2[index + 2][n - 1];
            // you dont eat slice
            int excl = 0 + dp2[index + 1][n];
            dp2[index][n] = max(incl, excl);
        }
    }
    int case2 = dp2[1][k / 3];
    return max(case1, case2);
}
int solveSO(vector<int> &slices)
{
    int k = slices.size();
    vector<int> prev1(k + 2, 0);
    vector<int> curr1(k + 2, 0);
    vector<int> next1(k + 2, 0);
    // for the case from 0 to k-2
    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= (k / 3); n++)
        {
            // you eat slice
            int incl = slices[index] + next1[n - 1];
            // you dont eat slice
            int excl = 0 + curr1[n];
            prev1[n] = max(incl, excl);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    // for the case from 1 to k-1
    int case1 = curr1[k / 3];
    vector<int> prev2(k + 2, 0);
    vector<int> curr2(k + 2, 0);
    vector<int> next2(k + 2, 0);
    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= (k / 3); n++)
        {
            // you eat slice
            int incl = slices[index] + next2[n - 1];
            // you dont eat slice
            int excl = 0 + curr2[n];
            prev2[n] = max(incl, excl);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    int case2 = curr2[k / 3];
    return max(case1, case2);
}
int main()
{
    vector<int> slices;
    slices.push_back(1);
    slices.push_back(2);
    slices.push_back(3);
    slices.push_back(4);
    slices.push_back(5);
    slices.push_back(6);
    int k = slices.size();
    int case1 = solve(0, k - 2, slices, k / 3);
    int case2 = solve(1, k - 1, slices, k / 3);
    int ans = max(case1, case2);
    cout << ans << endl; // Recursion
    vector<vector<int>> dp1(k, vector<int>(k, -1));
    vector<vector<int>> dp2(k, vector<int>(k, -1));
    int caseMem1 = solveMemo(0, k - 2, slices, k / 3, dp1);
    int caseMem2 = solveMemo(1, k - 1, slices, k / 3, dp2);
    int ansMem = max(caseMem1, caseMem2);
    cout << ansMem << endl;           // Recursion + Memoization
    cout << solveTab(slices) << endl; // Tabulation
    cout << solveSO(slices) << endl;  // Space Optimization
    return 0;
}