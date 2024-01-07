#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std; // Cycle Detection in undirected graph using BFS
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
bool bfs(vector<vector<int>> &adj, int src, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto neighbour : adj[front])
        {
            if (visited[front] && neighbour != parent[front])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                visited[front] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }
    return false;
}
string cycleDetection(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> adj = prepareAdjList(edges, N);
    unordered_map<int, bool> visited;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            if (bfs(adj, i, visited))
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
    cout << cycleDetection(edges, N);
    return 0;
}