#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long arr[n];
        for (long long i = 1; i <= n; i++)
        {
            arr[i - 1] = i;
        }
        for (long long k = 2; k <= n; k++)
        {
            long long i = 1;
            for (long long d = 1; d < k; d++)
            {
                if (k % d == 0)
                {
                    i = d;
                }
            }
            swap(arr[i - 1], arr[k - 1]);
        }
        for (long long i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}