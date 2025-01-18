#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> pre1(n + 1, 0), pre2(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre1[i] = pre1[i - 1] + (i * v[i]);
        pre2[i] = pre2[i - 1] + v[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (pre1[r] - pre1[l - 1]) - (l - 1) * (pre2[r] - pre2[l - 1]);
    }
    return 0;
}

// T.C:-O(n+q)