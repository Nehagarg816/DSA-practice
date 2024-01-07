#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std; // Bellman's Ford Algorithm
int Bellman_ford(vector<pair<pair<int, int>, int>> &edges, int V, int E, int src, int dest)
{
    vector<int> dist(V + 1, 1e9);
    dist[src] = 0;

    // loop for V times
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int w = edges[j].second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for negative cycle
    bool flag = false;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        if (dist[u] != 1e9 && dist[u] + w < dist[v])
        {
            flag = true;
        }
    }

    if (!flag)
    {
        return dist[dest];
    }
    return -1;
}
int main()
{
    vector<pair<pair<int, int>, int>> edges;

    edges.push_back(make_pair(make_pair(1, 2), 2));
    edges.push_back(make_pair(make_pair(2, 3), -1));
    edges.push_back(make_pair(make_pair(1, 3), 2));
    cout << Bellman_ford(edges, 3, 3, 1, 3);
    return 0;
}