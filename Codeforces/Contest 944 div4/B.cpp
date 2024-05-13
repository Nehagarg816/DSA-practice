#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int count = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                count++;
            }
        }
        if (count == s.length() - 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            s[s.length() - 1] = s[0];
            for (int i = 0; i <= s.length() - 2; i++)
            {
                s[i] = s[i + 1];
            }
            cout << s << endl;
        }
    }
}