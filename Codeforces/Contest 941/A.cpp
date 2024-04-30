#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long maxi = LLONG_MIN;
        long long ans = 0;
        unordered_map<long long, long long> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            int a = m[x]++;
            maxi = max(maxi, a);
        }
        ans = (maxi >= k ? k - 1 : n);
        cout << ans << endl;
    }
}