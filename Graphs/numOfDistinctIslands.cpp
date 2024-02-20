#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> ways = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(int row, int col, vector<pair<int, int>> &vec, vector<vector<int>> &vis, vector<vector<int>> &grid, int baseRow, int baseCol)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({abs(row - baseRow), abs(col - baseCol)});
        for (auto x : ways)
        {
            int nrow = row + x[0];
            int ncol = col + x[1];
            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vec, vis, grid, baseRow, baseCol);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vec, vis, grid, i, j);
                    s.insert(vec);
                }
            }
        }
        return s.size();
    }
};
int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {1, 1, 0, 1, 0}};
    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;
    return 0;
}