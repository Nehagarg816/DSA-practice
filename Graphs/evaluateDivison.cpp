#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(string a, string b, map<string, vector<string>> &graph, map<string, int> &vis, double &d, bool &found, map<string, double> &m)
{
    vis[a] = 1;
    if (found == true)
    {
        return;
    }
    for (auto c : graph[a])
    {
        if (vis[c] != 1)
        {
            d *= m[a + "->" + c];
            if (b == c)
            {
                found = true;
                return;
            }
            dfs(c, b, graph, vis, d, found, m);
            if (found == true)
            {
                return;
            }
            d /= m[a + "->" + c];
        }
    }
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    vector<double> ans;
    map<string, double> m;
    map<string, vector<string>> graph;
    for (int i = 0; i < equations.size(); i++)
    {
        string u = equations[i][0];
        string v = equations[i][1];
        m[u + "->" + v] = values[i];
        m[v + "->" + u] = 1 / values[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < queries.size(); i++)
    {
        string a = queries[i][0];
        string b = queries[i][1];
        if (graph.find(a) == graph.end() or graph.find(b) == graph.end())
        {
            ans.push_back(-1);
        }
        else
        {
            double d = 1;
            map<string, int> vis;
            bool found = false;
            if (a == b)
            {
                found = true;
            }
            else
            {
                dfs(a, b, graph, vis, d, found, m);
            }
            if (found == true)
            {
                ans.push_back(d);
            }
            else
            {
                ans.push_back(-1);
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<string>> equation;
    vector<double> values;
    vector<vector<string>> queries;
    equation.push_back({"a", "b"});
    equation.push_back({"b", "c"});
    values.push_back(2.0);
    values.push_back(3.0);
    queries.push_back({"a", "c"});
    queries.push_back({"b", "a"});
    queries.push_back({"a", "e"});
    queries.push_back({"a", "a"});
    queries.push_back({"x", "x"});
    vector<double> ans = calcEquation(equation, values, queries);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}