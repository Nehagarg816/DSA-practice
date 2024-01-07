#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int PrimsAlgo(int V, vector<pair<pair<int, int>, int>> &edge)
{
    unordered_map<int, list<pair<int, int>>> adj(V);
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i].first.first;
        int v = edge[i].first.second;
        int w = edge[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, false);
    int sum = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        int u = p.second;
        if (visited[u] == true)
        {
            continue;
        }
        sum += w;
        visited[u] = true;
        for (auto v : adj[u])
        {
            if (visited[v.first] == false)
            {
                pq.push({v.second, v.first});
            }
        }
    }
    return sum;
}

int main()
{
    vector<pair<pair<int, int>, int>> edge;
    edge.push_back(make_pair(make_pair(0, 1), 2));
    edge.push_back(make_pair(make_pair(0, 3), 6));
    edge.push_back(make_pair(make_pair(1, 2), 3));
    edge.push_back(make_pair(make_pair(1, 3), 8));
    edge.push_back(make_pair(make_pair(1, 4), 5));
    edge.push_back(make_pair(make_pair(2, 4), 7));
    int ans = PrimsAlgo(5, edge);
    cout << ans;
    return 0;
}