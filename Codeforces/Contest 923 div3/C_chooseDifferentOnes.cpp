#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        set<int> a, b, c;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x <= k)
            {
                a.insert(x);
                c.insert(x);
            }
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (x <= k)
            {
                b.insert(x);
                c.insert(x);
            }
        }
        if (a.size() >= k / 2 and b.size() >= k / 2 and c.size() == k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}