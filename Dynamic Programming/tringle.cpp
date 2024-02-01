#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &triangle, int n)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    int ans = INT_MAX;
    int down = triangle[i][j] + solve(i + 1, j, triangle, n);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n);
    ans = min(down, diagonal);
    return ans;
}
int solveMemo(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    int ans = INT_MAX;
    int down = triangle[i][j] + solveMemo(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + solveMemo(i + 1, j + 1, triangle, n, dp);
    ans = min(down, diagonal);
    dp[i][j] = ans;
    return dp[i][j];
}
int solveTab(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = INT_MAX;
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            ans = min(down, diagonal);
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveSO(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1)
            {
                curr[j] = triangle[i][j];
                continue;
            }
            int ans = INT_MAX;
            int down = triangle[i][j] + next[j];
            int diagonal = triangle[i][j] + next[j + 1];
            ans = min(down, diagonal);
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    vector<vector<int>> triangle;
    // triangle.push_back({2});
    // triangle.push_back({3, 4});
    // triangle.push_back({6, 5, 7});
    // triangle.push_back({4, 1, 8, 3});
    triangle.push_back({-10});
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << solve(0, 0, triangle, n) << endl;         // Recursion
    cout << solveMemo(0, 0, triangle, n, dp) << endl; // Recursion + Memoization
    cout << solveTab(triangle) << endl;               // Tabulation
    cout << solveSO(triangle) << endl;                // Space Optimized
    return 0;
}