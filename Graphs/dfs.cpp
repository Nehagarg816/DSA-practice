#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    void dfs(vector<int> adj[], vector<int> &ans, int node, unordered_map<int, bool> &visited)
    {
        ans.push_back(node);
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                dfs(adj, ans, i, visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, ans, i, visited);
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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}