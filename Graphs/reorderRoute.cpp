#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(int i, unordered_map<int, vector<int>> &m, vector<int> &vis)
{
    vis[i] = 1;
    for (int j : m[i])
    {
        if (j >= 0)
        {
            if (!vis[j])
            {
                dfs(j, m, vis);
            }
        }
        else
        {
            if (!vis[abs(j)])
            {
                ans++;
                dfs(abs(j), m, vis);
            }
        }
    }
}
int minReorder(int n, vector<vector<int>> &connections)
{
    unordered_map<int, vector<int>> m;
    vector<int> vis(n, 0);
    for (int i = 0; i < connections.size(); i++)
    {
        m[connections[i][1]].push_back(connections[i][0]);
        m[connections[i][0]].push_back(-connections[i][1]);
    }
    dfs(0, m, vis);
    if (ans == 0)
    {
        return ans;
    }
    return ans;
}
int main()
{
    vector<vector<int>> connections;
    connections.push_back({0, 1});
    connections.push_back({1, 3});
    connections.push_back({2, 3});
    connections.push_back({4, 0});
    connections.push_back({4, 5});
    cout << minReorder(6, connections);
    return 0;
}