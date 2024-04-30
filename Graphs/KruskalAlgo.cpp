#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std; // Kruskal's Algorithm for finding Minimum Spanning Tree of any Graph
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int> &parent, int n)
{
    if (parent[n] == n)
    {
        return n;
    }
    return parent[n] = findParent(parent, parent[n]);
}
void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanning(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];
        if (u != v)
        {
            minWeight += w;
            unionSet(parent, rank, u, v);
        }
    }
    return minWeight;
}
int main()
{
    vector<vector<int>> edges;
    edges.push_back({1, 2, 2});
    edges.push_back({1, 4, 1});
    edges.push_back({1, 5, 4});
    edges.push_back({2, 4, 3});
    edges.push_back({2, 3, 3});
    edges.push_back({2, 6, 7});
    edges.push_back({3, 4, 5});
    edges.push_back({3, 6, 8});
    edges.push_back({4, 5, 9});
    cout << "Minimum Spanning Tree Weight: " << minimumSpanning(edges, 7);
    return 0;
}