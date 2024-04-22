#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = abs(b - d);
        int y = a + x;
        int ans = 0;
        if (y < c or b > d)
        {
            ans = -1;
        }
        if (ans == -1)
            cout << ans << endl;
        else
        {
            int z = abs(c - y);
            cout << z + x << endl;
        }
    }
}