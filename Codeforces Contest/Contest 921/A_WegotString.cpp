#include <bits/stdc++.h>
using namespace std;
string solveStr(int n, int k)
{
    string s = "";
    for (int i = 0; i < k; i++)
    {
        char c = 'a' + i;
        s += c;
    }
    string ans = s;
    for (int i = 1; i < n; i++)
    {
        ans += s;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        cout << solveStr(n, k) << endl;
        t--;
    }
    return 0;
}