#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> Prims(int n, vector<pair<pair<int, int>, int>> &edge)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i].first.first;
        int v = edge[i].first.second;
        int w = edge[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    key[1] = 0;
    parent[1] = -1;
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        mst[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return ans;
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
    vector<pair<pair<int, int>, int>> ans;
    ans = Prims(5, edge);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i].second;
    }
    cout << sum;
    return 0;
}