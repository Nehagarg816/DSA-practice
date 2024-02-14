#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ways = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        dist[row][col] = steps;
        q.pop();
        for (auto x : ways)
        {
            int nrow = row + x[0];
            int ncol = col + x[1];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol])
            {
                q.push({{nrow, ncol}, steps + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> res = updateMatrix(mat);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}