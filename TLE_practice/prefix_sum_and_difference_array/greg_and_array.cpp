// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long n, m, k;
//     cin >> n >> m >> k;
//     vector<long long> v(n);
//     for (long long i = 0; i < n; i++)
//         cin >> v[i];
//     vector<pair<long long, pair<long long, long long>>> operations(m + 2);
//     for (long long i = 1; i <= m; i++)
//     {
//         long long l, r, d;
//         cin >> l >> r >> d;
//         operations[i] = {l, {r, d}};
//     }
//     vector<long long> diff(n + 2, 0), queries(m + 2, 0);
//     for (long long i = 0; i < k; i++)
//     {
//         long long x, y;
//         cin >> x >> y;
//         queries[x]++;
//         queries[y + 1]--;
//     }
//     for (long long i = 1; i <= m; i++)
//         queries[i] += queries[i - 1];
//     for (long long i = 1; i <= m; i++)
//     {
//         long long l = operations[i].first;
//         long long r = operations[i].second.first;
//         long long d = operations[i].second.second;
//         diff[l] += d * queries[i];
//         diff[r + 1] -= d * queries[i];
//     }
//     for (long long i = 0; i < n; i++)
//     {
//         diff[i + 1] += diff[i];
//         v[i] += diff[i + 1];
//     }
//     for (long long i = 0; i < n; i++)
//         cout << v[i] << " ";
//     cout << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int maxi = 200005;
bool vis1[maxi], vis2[maxi];
int col[maxi], cnt, n, e1, e2;
vector<int> graph1[maxi], graph2[maxi];
map<pair<int, int>, int> m;

void dfs2(int node)
{
    col[node] = cnt;
    vis2[node] = true;
    for (int nbr : graph2[node])
    {
        if (!vis2[nbr])
        {
            dfs2(nbr);
        }
    }
}
void dfs1(int node)
{
    vis1[node] = true;
    for (int nbr : graph1[node])
    {
        if (!vis1[nbr] && m[{node, nbr}] != 1)
        {
            dfs1(nbr);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> e1 >> e2;
        cnt = 0;
        m.clear();
        for (int i = 0; i < n; i++)
        {
            graph1[i].clear();
            graph2[i].clear();
            vis1[i] = false;
            vis2[i] = false;
        }
        for (int i = 0; i < e1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            graph1[u].push_back(v);
            graph1[v].push_back(u);
        }
        for (int i = 0; i < e2; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis2[i])
            {
                cnt++;
                dfs2(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int nbr : graph1[i])
            {
                if (col[i] != col[nbr])
                {
                    ans++;
                    m[{i, nbr}] = 1;
                }
            }
        }
        int cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis1[i])
            {
                cnt2++;
                dfs1(i);
            }
        }
        cout << ans / 2 + (cnt2 - cnt) << endl;
    }

    return 0;
}
