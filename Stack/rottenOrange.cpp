#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std; // Rotting Oranges
int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.empty())
    {
        return 0;
    }
    queue<pair<int, int>> q;
    int m = grid.size();
    int n = grid[0].size();
    int total = 0;
    int cnt = 0;
    int days = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0)
            {
                total++;
            }
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k > 0)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
            k--;
        }
        if (!q.empty())
        {
            days++;
        }
    }
    return (total == cnt) ? days : -1;
}
int main()
{
    vector<vector<int>> grid;
    grid.push_back({2, 0, 0, 2});
    grid.push_back({1, 0, 0, 1});
    grid.push_back({1, 1, 0, 1});
    grid.push_back({0, 0, 0, 1});
    cout << orangesRotting(grid);
    return 0;
}