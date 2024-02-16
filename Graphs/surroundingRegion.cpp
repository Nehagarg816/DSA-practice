#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ways = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = 1;
    for (auto x : ways)
    {
        int nrow = row + x[0];
        int ncol = col + x[1];
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and board[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, vis, board);
        }
    }
}
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        // first row
        if (!vis[0][j] and board[0][j] == 'O')
        {
            dfs(0, j, vis, board);
        }
        // last row
        if (!vis[n - 1][j] and board[n - 1][j] == 'O')
        {
            dfs(n - 1, j, vis, board);
        }
    }
    for (int i = 0; i < n; i++)
    {
        // first column
        if (!vis[i][0] and board[i][0] == 'O')
        {
            dfs(i, 0, vis, board);
        }
        // last column
        if (!vis[i][m - 1] and board[i][m - 1] == 'O')
        {
            dfs(i, m - 1, vis, board);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}
int main()
{
    vector<vector<char>> board = {{'X', 'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X', 'O'}, {'X', 'X', 'O', 'X', 'O'}, {'X', 'O', 'X', 'X', 'X'}, {'O', 'O', 'X', 'X', 'X'}};
    solve(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}