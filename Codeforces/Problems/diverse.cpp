#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll tot = (ll)n * (n - 1) / 2, same = 0;
    for (auto it : mp)
    {
        ll cnt = it.second;
        same += cnt * (cnt - 1) / 2;
    }
    vector<int> c;
    for (auto it : mp)
    {
        if (it.second > 1)
            c.push_back(it.second);
    }
    sort(c.begin(), c.end());
    int m = c.size();
    for (int j = m - 1; j >= 0; j--)
    {
        if (k == 0)
            break;
        if (c[j] > 1)
        {
            int s = min(k, c[j] - 1);
            same -= (c[j] * (c[j] - 1)) / 2;
            same += ((c[j] - s) * (c[j] - s - 1)) / 2;
            k -= s;
        }
    }
    ll ans = tot - same;
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}