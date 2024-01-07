#include <iostream>
#include <queue>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> prepareAdj(vector<pair<int, int>> &edges, int N)
{
    vector<vector<int>> ans(N);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    return ans;
}
vector<int> shortestPath(vector<pair<int, int>> &edges, int N, int M, int src)
{
    vector<vector<int>> adj = prepareAdj(edges, N);
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i : adj[curr])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    int currentNode = M;
    while (currentNode != src)
    {
        ans.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    ans.push_back(src);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({1, 4});
    edges.push_back({2, 1});
    edges.push_back({2, 5});
    edges.push_back({3, 1});
    edges.push_back({3, 8});
    edges.push_back({4, 1});
    edges.push_back({4, 6});
    edges.push_back({5, 2});
    edges.push_back({5, 8});
    edges.push_back({6, 4});
    edges.push_back({6, 7});
    edges.push_back({7, 6});
    edges.push_back({7, 8});
    edges.push_back({8, 3});
    edges.push_back({8, 5});
    edges.push_back({8, 7});
    int N = 9;
    int M = 8;
    int src = 1;
    vector<int> ans = shortestPath(edges, N, M, src);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}