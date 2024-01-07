#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, vector<int> &result, int &timer, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, disc, low, vis, result, timer, adj);
            low[node] = min(low[node], low[nbr]);
            // check articulation point condition
            if (low[nbr] >= disc[node] && parent != -1)
            {
                result.push_back(node);
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if (parent == -1 && child > 1)
    {
        result.push_back(node);
    }
}
vector<int> articulation_point(vector<vector<int>> &edges, int V)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(V);
    vector<int> low(V);
    int parent = -1;
    vector<int> result;
    unordered_map<int, bool> vis;
    for (int i = 0; i < V; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, disc, low, vis, result, timer, adj);
        }
    }
    sort(result.begin(), result.end());
    auto dup = unique(result.begin(), result.end());
    result.erase(dup, result.end());
    return result;
}
int main()
{
    vector<vector<int>> edges;
    // edges.push_back({0, 3});
    // edges.push_back({3, 4});
    // edges.push_back({0, 1});
    // edges.push_back({4, 0});
    // edges.push_back({1, 2});
    // int N=5;
    edges.push_back({5, 0});
    edges.push_back({4, 6});
    edges.push_back({1, 3});
    edges.push_back({5, 2});
    edges.push_back({0, 4});
    edges.push_back({4, 3});
    int N = 7;
    vector<int> ans = articulation_point(edges, N);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}