#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; // Cycle Detection in undirected graph using DFS
vector<vector<int>> prepareAdjList(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> adj(N);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
bool dfs(vector<vector<int>> &Adj, int node, int parent, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto neighbour : Adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(Adj, neighbour, node, visited))
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}
string CycleDetection(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> Adj = prepareAdjList(edges, N);
    unordered_map<int, bool> visited;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            bool ans = dfs(Adj, i, -1, visited);
            if (ans == true)
            {
                return "Yes! Cycle is Detection";
            }
            else
            {
                return "No! Cycle is not Detection";
            }
        }
    }
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({4, 2});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    int N = 5;
    cout << CycleDetection(edges, N);
    return 0;
}