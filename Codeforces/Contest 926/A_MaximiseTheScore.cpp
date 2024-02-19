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
        int arr[2 * n];
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        sort(arr, arr + 2 * n);
        for (int i = 0; i < 2 * n; i = i + 2)
        {
            ans += min(arr[i], arr[i + 1]);
        }
        cout << ans << endl;
    }
}