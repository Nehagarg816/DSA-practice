#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(v.begin(), v.end());
    vector<int> prefix_sum(n, 0);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        prefix_sum[l]++;
        if (r + 1 < n)
            prefix_sum[r + 1]--;
    }
    for (int i = 1; i < n; i++)
        prefix_sum[i] += prefix_sum[i - 1];
    long long ans = 0;
    sort(prefix_sum.begin(), prefix_sum.end());
    for (int i = 0; i < n; i++)
    {
        ans += 1LL * v[i] * prefix_sum[i];
    }
    cout << ans << endl;
    return 0;
}