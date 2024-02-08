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
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        vector<int> dp(n + 2);
        dp[n] = n + 10;
        for (int i = n - 1; i >= 1; i--)
        {
            if (arr[i] == arr[i + 1])
                dp[i] = dp[i + 1];
            else
                dp[i] = i + 1;
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            if (dp[l] <= r)
            {
                cout << l << " " << dp[l] << "\n";
            }
            else
            {
                cout << "-1 -1\n";
            }
        }
        cout << "\n";
    }
    return 0;
}