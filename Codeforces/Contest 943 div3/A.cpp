#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int ans = 0;
        int maxi = INT_MIN;
        for (int y = 1; y < x; y++)
        {
            int res = __gcd(x, y) + y;
            if (maxi < res)
            {
                maxi = res;
                ans = y;
            }
        }
        cout << ans << endl;
    }
}