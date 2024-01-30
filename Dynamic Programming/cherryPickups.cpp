#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Maximum Number of Cherries Picked
vector<vector<int>> ways = {{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};
int dp[50][50][50][50];
int solve(vector<vector<int>> &grid, int r1, int c1, int r2, int c2)
{
    int n = grid.size();
    if (r1 == n - 1 and c1 == n - 1 and r2 == n - 1 and c2 == n - 1)
    {
        return grid[n - 1][n - 1];
    }
    if (dp[r1][c1][r2][c2] != -1)
    {
        return dp[r1][c1][r2][c2];
    }
    int row1, row2, col1, col2;
    int ans = 0;
    if (r1 == r1 and c1 == c2)
    {
        ans += grid[r1][c1];
    }
    else
    {
        ans += grid[r1][c1] + grid[r2][c2];
    }
    int maxi = INT_MIN;
    for (auto x : ways)
    {
        row1 = r1 + x[0];
        col1 = c1 + x[1];
        row2 = r2 + x[2];
        col2 = c2 + x[3];
        if (row1 >= n or col1 >= n or row2 >= n or col2 >= n or grid[row1][col1] == -1 or grid[row2][col2] == -1)
        {
            continue;
        }
        maxi = max(maxi, solve(grid, row1, col1, row2, col2));
    }
    ans += maxi;
    return dp[r1][c1][r2][c2] = ans;
}
int dp2[50][50][50];
int solve2(vector<vector<int>> &grid, int r1, int c1, int r2)
{
    int c2 = r1 + c1 - r2;
    int n = grid.size();
    if (r1 == n - 1 and c1 == n - 1 and r2 == n - 1 and c2 == n - 1)
    {
        return grid[n - 1][n - 1];
    }
    if (dp2[r1][c1][r2] != -1)
    {
        return dp2[r1][c1][r2];
    }
    int row1, row2, col1, col2;
    int ans = 0;
    if (r1 == r1 and c1 == c2)
    {
        ans += grid[r1][c1];
    }
    else
    {
        ans += grid[r1][c1] + grid[r2][c2];
    }
    int maxi = INT_MIN;
    for (auto x : ways)
    {
        row1 = r1 + x[0];
        col1 = c1 + x[1];
        row2 = r2 + x[2];
        col2 = c2 + x[3];
        if (row1 >= n or col1 >= n or row2 >= n or col2 >= n or grid[row1][col1] == -1 or grid[row2][col2] == -1)
        {
            continue;
        }
        maxi = max(maxi, solve2(grid, row1, col1, row2));
    }
    ans += maxi;
    return dp2[r1][c1][r2] = ans;
}
int main()
{
    vector<vector<int>> grid; //[[0,1,-1],[1,0,-1],[1,1,1]]
    grid.push_back({0, 1, -1});
    grid.push_back({1, 0, -1});
    grid.push_back({1, 1, 1});
    int n = grid.size();
    memset(dp, -1, sizeof(dp));
    cout << (solve(grid, 0, 0, 0, 0) < 0 ? 0 : solve(grid, 0, 0, 0, 0)) << endl; // 4D DP
    memset(dp2, -1, sizeof(dp2));
    cout << (solve2(grid, 0, 0, 0) < 0 ? 0 : solve2(grid, 0, 0, 0)) << endl; // 3D DP
    return 0;
}