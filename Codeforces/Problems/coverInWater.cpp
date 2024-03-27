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
        string s;
        cin >> s;
        int cnt = 0;
        int dot = 0;
        for (char x : s)
        {
            if (x == '#')
            {
                if (dot >= 3)
                {
                    cnt = 2;
                    break;
                }
                else
                {
                    cnt += dot;
                    dot = 0;
                }
            }
            else
            {
                dot++;
            }
        }
        if (dot >= 3)
        {
            cnt = 2;
        }
        else
        {
            cnt += dot;
            dot = 0;
        }
        cout << cnt << endl;
    }
}