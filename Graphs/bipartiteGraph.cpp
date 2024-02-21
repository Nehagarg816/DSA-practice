#include <bits/stdc++.h>
using namespace std;
void adjacencyList(vector<vector<int>> &edges, vector<int> adj[])
{
    int n = edges.size();
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
bool solve(int start, vector<int> &color, int V, vector<int> adj[])
{
    color[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nbr : adj[node])
        {
            if (color[nbr] == -1)
            {
                color[nbr] = !color[node];
                q.push(nbr);
            }
            else if (color[nbr] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!solve(i, color, V, adj))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> edges;
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({2, 6});
    edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({6, 5});
    edges.push_back({4, 7});
    edges.push_back({7, 8});
    int V = 8;
    vector<int> adj[V];
    adjacencyList(edges, adj);
    if (isBipartite(V, adj))
    {
        cout << "Bipartite Graph";
    }
    else
    {
        cout << "Not a Bipartite Graph";
    }
    return 0;
}