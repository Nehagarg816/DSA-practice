#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(vector<int> adj[], vector<int> &ans, unordered_map<int, bool> &vis, int node)
    {
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for (int i : adj[frontNode])
            {
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfs(adj, ans, visited, i);
            }
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}