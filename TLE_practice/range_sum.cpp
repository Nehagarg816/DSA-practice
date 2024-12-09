#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (auto &it : v)
        cin >> it;
    vector<long long> pre(n);
    pre[0] = v[0];
    for (long long i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == 0)
            cout << pre[r] << endl;
        else
            cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}