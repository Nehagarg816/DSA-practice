#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        int ans = 0;
        bool flag = false;
        while (ans <= 5)
        {
            if (x.find(s) != string::npos)
            {
                flag = true;
                cout << ans << endl;
                break;
            }
            x += x;
            ans++;
        }
        if (flag == false)
        {
            cout << "-1" << endl;
        }
    }
}