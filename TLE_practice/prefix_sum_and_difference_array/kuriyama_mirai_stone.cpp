#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &it : v)
        cin >> it;
    vector<long long> pre(n);
    vector<long long> pre_sort(n);
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    sort(v.begin(), v.end());
    pre_sort[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre_sort[i] = pre_sort[i - 1] + v[i];
    }
    long long q;
    cin >> q;
    while (q--)
    {
        long long l, r, x;
        cin >> x >> l >> r;
        l--;
        r--;
        if (x == 1)
        {
            if (l == 0)
                cout << pre[r] << endl;
            else
                cout << pre[r] - pre[l - 1] << endl;
        }
        else
        {
            if (l == 0)
                cout << pre_sort[r] << endl;
            else
                cout << pre_sort[r] - pre_sort[l - 1] << endl;
        }
    }
}