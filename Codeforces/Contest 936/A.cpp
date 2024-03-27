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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        sort(arr, arr + n);
        int mid = (n / 2);
        if (n % 2 == 0)
        {
            mid--;
        }
        for (int i = mid; i < n; i++)
        {
            if (arr[i] == arr[mid])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}