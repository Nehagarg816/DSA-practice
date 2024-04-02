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
        int a[n];
        int mini = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < mini)
            {
                mini = a[i];
                cnt = 1;
            }
            else if (a[i] == mini)
            {
                cnt++;
            }
        }
        if (cnt == n)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << cnt << " " << n - cnt << endl;
        for (int i = 0; i < cnt; i++)
        {
            cout << mini << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != mini)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
}