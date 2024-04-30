#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        long long cnt = 0;
        for (long long i = 1; i <= m; i++)
        {
            cnt += (n + i) / (i * i);
        }
        cnt--;
        cout << cnt << endl;
    }
}