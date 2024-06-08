#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &m, int n)
{
    if ((x >= 0 and x < n) and (y >= 0 and y < n) and vis[x][y] != 1 and m[x][y] == 1)
    {
        return true;
    }
    return false;
}
void solve(int x, int y, vector<vector<bool>> &vis, vector<string> &ans, vector<vector<int>> &m, int n, string s)
{
    if (x == n - 1 and y == n - 1)
    {
        ans.push_back(s);
        return;
    }
    // D
    if (isSafe(x + 1, y, vis, m, n))
    {
        vis[x][y] = 1;
        solve(x + 1, y, vis, ans, m, n, s + "D");
    }
    // L
    if (isSafe(x, y - 1, vis, m, n))
    {
        vis[x][y] = 1;
        solve(x, y - 1, vis, ans, m, n, s + "L");
    }
    // R
    if (isSafe(x, y + 1, vis, m, n))
    {
        vis[x][y] = 1;
        solve(x, y + 1, vis, ans, m, n, s + "R");
    }
    // U
    if (isSafe(x - 1, y, vis, m, n))
    {
        vis[x][y] = 1;
        solve(x - 1, y, vis, ans, m, n, s + "U");
    }
    vis[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    if (m[0][0] == 0)
    {
        return {};
    }
    vector<string> ans;
    string s;
    solve(0, 0, vis, ans, m, n, s);
    return ans;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(m, 4);
    for (auto x : ans)
    {
        cout << x << endl;
    }
}