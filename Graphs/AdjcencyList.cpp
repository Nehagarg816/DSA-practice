#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> prepareAdj(vector<pair<int, int>> edges, int N)
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
void printAdjList(vector<pair<int, int>> edges, int N)
{
    vector<vector<int>> adj = prepareAdj(edges, N);
    for (int u = 0; u < N; u++)
    {
        cout << u << "->";
        for (int v : adj[u])
        {
            cout << v << ",";
        }
        cout << endl;
    }
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 4});
    edges.push_back({4, 1});
    edges.push_back({4, 3});
    edges.push_back({1, 3});
    edges.push_back({1, 2});
    edges.push_back({3, 2});
    int N = 5;
    printAdjList(edges, N);
    return 0;
}