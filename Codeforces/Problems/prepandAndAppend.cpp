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
        int l = 0, r = n - 1;
        while (l <= r)
        {
            if ((s[l] == '1' and s[r] == '0') or (s[l] == '0' and s[r] == '1'))
                l++, r--;
            else
                break;
        }
        cout << r - l + 1 << endl;
    }
}