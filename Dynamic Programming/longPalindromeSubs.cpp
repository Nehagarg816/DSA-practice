#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Minimum number of operations required to make a string subsequence palindromic.
int solve(string s)
{
    map<char, int> m;
    int n = s.length();
    string ans1 = "", ans2 = "";
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < m[i] / 2; j++)
        {
            ans1 += char(i);
        }
        for (int j = (m[i] + 1) / 2; j < m[i]; j++)
        {
            ans2 += char(i);
        }
    }
    reverse(ans2.begin(), ans2.end());
    bool f = false;
    for (int i = 0; i < 256; i++)
    {
        if (m[i] % 2 == 0)
        {
            if (!f)
            {
                ans1 += char(i);
                f = true;
            }
        }
    }
    return (ans1.size() + ans2.size());
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}