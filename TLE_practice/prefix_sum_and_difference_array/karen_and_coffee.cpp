#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> l(n, 0), r(n, 0);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<int> prefix_sum(200005, 0);
    for (int i = 0; i < n; i++)
    {
        prefix_sum[l[i]]++;
        if (r[i] < 200005)
            prefix_sum[r[i] + 1]--;
    }
    for (int i = 1; i < 200005; i++)
        prefix_sum[i] += prefix_sum[i - 1];
    vector<int> flag(200005, 0);
    for (int i = 0; i < 200005; i++)
    {
        if (prefix_sum[i] >= k)
            flag[i] = 1;
    }
    for (int i = 1; i < 200005; i++)
        flag[i] += flag[i - 1];
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << flag[b] - flag[a - 1] << endl;
    }
    return 0;
}