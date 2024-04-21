#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        if (n < 3)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for (auto x : m)
        {
            ans += x.second / 3;
        }
        cout << ans << endl;
    }
}