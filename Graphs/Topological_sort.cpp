#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std; // Topological Sort
vector<vector<int>> prepareAdjList(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    return adj;
}
void dfsTopologicalSort(vector<vector<int>> &adj, int node, int parent, unordered_map<int, bool> &visited, stack<int> &s)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfsTopologicalSort(adj, neighbour, node, visited, s);
        }
    }
    s.push(node);
}
vector<int> TopologicalSort(vector<pair<int, int>> &edges, int N)
{
    unordered_map<int, bool> visited;
    stack<int> s;
    vector<vector<int>> adj = prepareAdjList(edges, N);
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfsTopologicalSort(adj, i, -1, visited, s);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({2, 4});
    edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({4, 6});
    edges.push_back({5, 6});
    int N = 7;
    vector<int> sorted = TopologicalSort(edges, N);
    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
    return 0;
}