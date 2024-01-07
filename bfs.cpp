#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
vector<vector<int>> AdjacencyList(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
void bfs(vector<vector<int>> &edges, int node, queue<int> &q, unordered_map<int, bool> &vis, int n, vector<int> &ans)
{
    vector<vector<int>> adj = AdjacencyList(edges, n);
    q.push(node);
    vis[node] = true;
    ans.push_back(node);
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            q.pop();
            bfs(edges, nbr, q, vis, n, ans);
        }
    }
    q.pop();
}
int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 3});
    edges.push_back({1, 3});
    edges.push_back({1, 2});
    edges.push_back({1, 4});
    int N = 5;
    queue<int> q;
    vector<int> ans;
    unordered_map<int, bool> vis;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            bfs(edges, i, q, vis, N, ans);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}