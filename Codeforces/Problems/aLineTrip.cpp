#include <bits/stdc++.h>
using namespace std; // Line Trip Codeforces Problem
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, x;
        cin >> n >> x;
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            ans = max(ans, ele - prev);
            prev = ele;
        }
        ans = max(ans, 2 * (x - prev));
        cout << ans << endl;
        t--;
    }
    return 0;
}