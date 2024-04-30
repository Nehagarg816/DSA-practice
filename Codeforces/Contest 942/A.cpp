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
        vector<int> b(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                for (int j = n - 1; j > i; j--)
                {
                    a[j] = a[j - 1];
                }
                a[i] = b[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
}