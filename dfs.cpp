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
void dfs(vector<vector<int>> &edges, int node, unordered_map<int, bool> &visited, vector<int> &ans, int n)
{
    vector<vector<int>> adj = AdjacencyList(edges, n);
    ans.push_back(node);
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfs(edges, nbr, visited, ans, n);
        }
    }
}
int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 2});
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({2, 4});
    edges.push_back({3, 4});
    int N = 5;
    unordered_map<int, bool> visited;
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(edges, i, visited, ans, N);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}