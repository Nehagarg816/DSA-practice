#include <bits/stdc++.h>
using namespace std;
int solve(int n, string &s)
{
    int ans = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (s[i] != 'B')
        {
            i++;
        }
        if (s[j] != 'B')
        {
            j--;
        }
        if (s[i] == 'B' and s[j] != 'B')
        {
            j--;
        }
        if (s[i] != 'B' and s[j] == 'B')
        {
            i++;
        }
        if (s[i] == 'B' and s[j] == 'B')
        {
            int diff = j - i + 1;
            ans = max(ans, diff);
            i++;
            j--;
        }
    }
    return ans;
}
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
        cout << solve(n, s);
    }
    return 0;
}