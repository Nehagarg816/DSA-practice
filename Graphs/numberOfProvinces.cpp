#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<bool> &vis, int src, vector<vector<int>> &isConnected)
{
    int n = isConnected[src].size();
    vis[src] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] and i != src and isConnected[src][i] == 1)
        {
            dfs(vis, i, isConnected);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(vis, i, isConnected);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<vector<int>> isConnected;
    isConnected.push_back({1, 1, 0});
    isConnected.push_back({1, 1, 0});
    isConnected.push_back({0, 0, 1});
    cout << findCircleNum(isConnected);
    return 0;
}