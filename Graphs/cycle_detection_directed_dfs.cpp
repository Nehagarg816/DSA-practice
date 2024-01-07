#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; // Cycle Detection in directed graph using DFS
vector<vector<int>> prepareAdjList(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> adj(N);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    return adj;
}
bool dfsCycle(vector<vector<int>> &adj, int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited)
{
    visited[node] = true;
    dfsvisited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfsCycle(adj, neighbour, node, visited, dfsvisited))
            {
                return true;
            }
        }
        else if (dfsvisited[neighbour])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}
string CycleDetection(vector<pair<int, int>> &edges, int N)
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    vector<vector<int>> adj = prepareAdjList(edges, N);
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            if (dfsCycle(adj, i, -1, visited, dfsvisited))
            {
                return "Yes! Cycle is Detected";
            }
        }
    }
    return "No! Cycle is not Detected";
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({2, 4});
    edges.push_back({3, 7});
    edges.push_back({3, 8});
    edges.push_back({4, 5});
    edges.push_back({5, 6});
    edges.push_back({8, 7});
    edges.push_back({6, 4});
    int N = 9;
    cout << CycleDetection(edges, N);
    return 0;
}