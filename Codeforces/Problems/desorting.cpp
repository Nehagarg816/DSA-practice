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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mini = INT_MAX;
        int ans = 0;
        int x = 0;
        int y = 0;
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                flag = true;
            }
            int diff = abs(a[i] - a[i - 1]);
            mini = min(mini, diff);
            x = i;
            y = i - 1;
        }
        if (flag == true)
        {
            cout << 0 << endl;
            continue;
        }
        if (mini == 0)
        {
            ans = 1;
        }
        else
        {
            ans = mini / 2 + 1;
        }
        cout << ans << endl;
    }
}