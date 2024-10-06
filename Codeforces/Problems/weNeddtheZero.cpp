#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ans ^= arr[i];
        }
        if (!ans)
            cout << "0" << endl;
        else
        {
            if (n % 2 == 1)
                cout << ans << endl;
            else
                cout << "-1" << endl;
        }
    }
}