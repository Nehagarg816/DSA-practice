#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "}";
            }
            cout << endl;
        }
    }
    void dfs(stack<int> &s, int node, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(s, i.first, visited);
            }
        }
        s.push(node);
    }
    void ShortestPath(stack<int> &s, int src, vector<int> &dest)
    {
        dest[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (dest[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (dest[top] + i.second < dest[i.first])
                    {
                        dest[i.first] = dest[top] + i.second;
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.print();
    // Topological Sort
    stack<int> s;
    int n = 6;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(s, i, visited);
        }
    }
    int src = 1;
    vector<int> dest(n);
    for (int i = 0; i < n; i++)
    {
        dest[i] = INT_MAX;
    }
    g.ShortestPath(s, src, dest);
    for (int i = 0; i < dest.size(); i++)
    {
        if (dest[i] == INT_MAX)
        {
            dest[i] = -1;
        }
    }
    for (int i = 0; i < dest.size(); i++)
    {
        cout << dest[i] << " ";
    }
    return 0;
}