#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, k;
        cin >> a >> b >> c >> k;
        long long cnt = 0;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                if (k % (i * j) == 0 and (k / (i * j) <= c))
                    cnt = max(cnt, (a - i + 1) * (b - j + 1) * (c - (k / (i * j)) + 1));
            }
        }
        cout << cnt << endl;
    }
}