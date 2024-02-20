#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ways = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (auto x : ways)
        {
            int nrow = row + x[0];
            int ncol = col + x[1];
            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 and !vis[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 1, 1}, {0, 0, 1, 1, 0}, {0, 1, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 1, 1}};
    cout << numEnclaves(grid) << endl;
    return 0;
}