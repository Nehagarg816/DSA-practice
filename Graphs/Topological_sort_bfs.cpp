#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std; // Topological sort using bfs (Kahn's algorithm)
vector<int> TopologicalSort(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> adj(N);
    vector<int> indegree(N, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (int neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({2, 5});
    edges.push_back({3, 5});
    edges.push_back({5, 4});
    int N = 6;
    vector<int> ans = TopologicalSort(edges, N);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}