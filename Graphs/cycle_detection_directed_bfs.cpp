#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std; // Cycle Detection in directed graph using bfs
bool bfsCycleDetect(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> adj(N);
    unordered_map<int, int> indegree;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    if (count == N)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    vector<pair<int, int>> edges;
    // edges.push_back({1, 2});
    // edges.push_back({2, 3});
    // edges.push_back({2, 4});
    // edges.push_back({3, 7});
    // edges.push_back({3, 8});
    // edges.push_back({4, 5});
    // edges.push_back({5, 6});
    // edges.push_back({8, 7});
    // edges.push_back({6, 4});
    edges.push_back({5, 3});
    edges.push_back({3, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 4});
    edges.push_back({4, 0});
    int N = 6;
    cout << bfsCycleDetect(edges, N);
    return 0;
}