#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (auto &it : v)
        cin >> it;
    long long pre = 0;
    map<long long, long long> m;
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        pre += v[i];
        if (pre == x)
            ans++;
        if (m.count(pre - x))
            ans += m[pre - x];
        m[pre]++;
    }
    cout << ans << endl;
    return 0;
}