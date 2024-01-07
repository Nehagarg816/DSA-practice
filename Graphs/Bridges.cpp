#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
// Tarjan's Algorithm
void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, vector<vector<int>> &ans, int &timer, vector<vector<int>> &adj)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, disc, low, vis, ans, timer, adj);
            low[node] = min(low[node], low[nbr]);
            // check if the edge is bridge
            if (low[nbr] > low[node])
            {
                vector<int> result;
                result.push_back(node);
                result.push_back(nbr);
                ans.push_back(result);
            }
        }
        else
        {
            // Back edge
            low[node] = min(low[node], disc[node]);
        }
    }
}
vector<vector<int>> bridges(vector<vector<int>> &edges, int V)
{
    // Prepare Adjacency List
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    // discovery time(original time)
    vector<int> disc(V);
    // Earliest possible time
    vector<int> low(V);
    int parent = -1;
    unordered_map<int, bool> vis;
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, disc, low, vis, ans, timer, adj);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({0, 2});
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    int V = 5;
    vector<vector<int>> ans = bridges(edges, V);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}