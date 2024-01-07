#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std; // Kosaraju's Algorithm
void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}
void revdfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    vis[node] = true;
    for (auto nbr : transpose[node])
    {
        if (!vis[nbr])
        {
            revdfs(nbr, vis, transpose);
        }
    }
}
int StronglyConnected(vector<vector<int>> &edges, int V)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    stack<int> st;
    unordered_map<int, bool> vis;
    // Topological Sort
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    // Transpose of graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < V; i++)
    {
        vis[i] = false;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    int count = 0;
    // DFS on transpose
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            count++;
            revdfs(top, vis, transpose);
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 0});
    edges.push_back({1, 3});
    edges.push_back({3, 4});
    int N = 5;
    cout << StronglyConnected(edges, N);
    return 0;
}