#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ways = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
// dfs function to fill the color of each cell in the grid
void dfs(int row, int col, int ini, vector<vector<int>> &ans, vector<vector<int>> &image, int color)
{
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = color;
    for (auto x : ways)
    {
        int nrow = row + x[0];
        int ncol = col + x[1];
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and ans[nrow][ncol] != color and image[nrow][ncol] == ini)
        {
            dfs(nrow, ncol, ini, ans, image, color);
        }
    }
}
// bfs function to fill the color of each cell in the grid
void bfs(int row, int col, int ini, vector<vector<int>> &ans, vector<vector<int>> &image, int color)
{
    int n = image.size();
    int m = image[0].size();
    ;
    queue<pair<int, int>> q;
    q.push({row, col});
    ans[row][col] = color;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int newRow = it.first;
        int newCol = it.second;
        for (auto x : ways)
        {
            int nrow = newRow + x[0];
            int ncol = newCol + x[1];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and ans[nrow][ncol] != color and image[nrow][ncol] == ini)
            {
                q.push({nrow, ncol});
                ans[nrow][ncol] = color;
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int iniColor = image[sr][sc];
    // dfs(sr, sc, iniColor, ans, image, color);
    bfs(sr, sc, iniColor, ans, image, color);
    return ans;
}
int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {2, 2, 0}, {2, 2, 2}};
    vector<vector<int>> ans = floodFill(image, 2, 0, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}