#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v = 0, f = 0;
        string ans, s = "", s2 = "", s3 = "";

        cin >> s;

        v = s[0] - '0';
        v = 10 * v + s[1] - '0';
        if (v > 12)
        {
            v -= 12;

            f = 1;
        }
        else if (v == 0)
        {
            v = 12;
        }
        else if (v == 12)
            f = 1;
        if (f == 1)
            s3 = "PM";
        else
            s3 = "AM";

        s2 = to_string(v);
        if (v < 10)
            ans += '0';
        ans += s2;

        ans += ':';
        ans += s[3];
        ans += s[4];
        ans += " ";
        ans += s3;

        cout << ans << endl;
    }
}