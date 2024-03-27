#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long ans = 0;
        int i = 0;
        while (i <= k)
        {
            long long sum = 0;
            for (long long x : arr)
            {
                sum += x;
            }
            if (sum < 0)
            {
                sum = 0;
            }
            ans = sum;
            arr.push_back(sum);
            i++;
        }
        if (ans < 0)
        {
            cout << mod - 1 << endl;
            continue;
        }
        cout << ans % mod << endl;
    }
    return 0;
}
