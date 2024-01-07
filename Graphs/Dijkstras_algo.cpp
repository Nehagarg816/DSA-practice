#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <climits>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> &edges, int S)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    set<pair<int, int>> s;
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[S] = 0;
    s.insert(make_pair(dist[S], S));
    while (!s.empty())
    {
        auto top = *(s.begin());
        int topDistance = top.first;
        int topNode = top.second;
        s.erase(s.begin());
        for (auto neighbour : adj[topNode])
        {
            if (neighbour.second + topDistance < dist[neighbour.first])
            {
                auto rec = s.find(make_pair(dist[neighbour.first], neighbour.first));
                if (rec != s.end())
                {
                    s.erase(rec);
                }
                dist[neighbour.first] = neighbour.second + topDistance;
                s.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 1, 1});
    edges.push_back({0, 2, 6});
    edges.push_back({1, 2, 3});
    vector<int> ans = dijkstra(3, edges, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}