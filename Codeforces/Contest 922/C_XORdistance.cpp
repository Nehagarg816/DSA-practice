#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, r;
        cin >> a >> b >> r;
        long long ans = LLONG_MAX;
        for (long long x = 0; x <= r; x++)
        {
            long long a_xor = a ^ x;
            long long b_xor = b ^ x;
            long long dis = abs(a_xor - b_xor);
            ans = min(ans, dis);
        }
        cout << ans << endl;
    }
    return 0;
}
