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
        int maxi = INT_MIN;
        int ans = n;
        for (int x = 2; x <= n; x++)
        {
            int k = n / x;
            int sum = (k * (k + 1)) / 2;
            if (x * sum > maxi)
            {
                maxi = x * sum;
                ans = x;
            }
        }
        cout << ans << endl;
    }
}