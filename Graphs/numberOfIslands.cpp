#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Number of Islands
vector<vector<int>> ways = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int rowIndex = q.front().first;
        int colIndex = q.front().second;
        q.pop();
        for (auto x : ways)
        {
            int nrow = rowIndex + x[0];
            int ncol = colIndex + x[1];
            if (nrow < n and nrow >= 0 and ncol < m and ncol >= 0 and grid[nrow][ncol] == '1' and !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] and grid[row][col] == '1')
            {
                bfs(row, col, grid, vis);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<vector<char>> grid;
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '1', '0', '0'});
    grid.push_back({'0', '0', '0', '1', '1'});
    cout << numIslands(grid);
    return 0;
}