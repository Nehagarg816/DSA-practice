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
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        maxi = max(maxi, a[i]);
        for (int i = 0; i <= maxi + 1; i++)
        {
            bool flag = false;
            vector<int> b(n);
            for (int j = 0; j < n; j++)
            {
                b[j] = a[j] ^ i;
            }
            for (int k : b)
            {
                x ^= k;
                if (x == 0)
                {
                    flag == true;
                }
            }
            if (flag == true)
            {
                cout << i << endl;
            }
        }
    }
}