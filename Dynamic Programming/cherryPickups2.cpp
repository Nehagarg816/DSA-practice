#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j1, int j2, vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i >= m or i < 0 or j1 >= n or j1 < 0 or j2 >= n or j2 < 0)
    {
        return 0;
    }
    int curr = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
    int ans = 0;
    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            ans = max(ans, curr + solve(i + 1, j1 + d1, j2 + d2, grid));
        }
    }
    return ans;
}
int solveMemo(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i >= m or i < 0 or j1 >= n or j1 < 0 or j2 >= n or j2 < 0)
    {
        return 0;
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int curr = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
    int ans = 0;
    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            ans = max(ans, curr + solveMemo(i + 1, j1 + d1, j2 + d2, grid, dp));
        }
    }
    dp[i][j1][j2] = ans;
    return dp[i][j1][j2];
}
int solveTab(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j1 = n - 1; j1 >= 0; j1--)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int ans = 0;
                int curr = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        if (i + 1 < m and j1 + d1 < n and j2 + d2 < n and j1 + d1 >= 0 and j2 + d2 >= 0)
                            ans = max(ans, curr + dp[i + 1][j1 + d1][j2 + d2]);
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    return dp[0][0][n - 1];
}
int main()
{
    vector<vector<int>> grid;
    grid.push_back({3, 1, 1});
    grid.push_back({2, 5, 1});
    grid.push_back({1, 5, 5});
    grid.push_back({2, 1, 1});
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    cout << solve(0, 0, n - 1, grid) << endl;         // Recursion
    cout << solveMemo(0, 0, n - 1, grid, dp) << endl; // Memoization
    cout << solveTab(grid) << endl;                   // Tabulation
    return 0;
}