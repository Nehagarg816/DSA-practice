#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int first = max(1, x - 52);
        int second = max(1, x - first - 26);
        int third = max(1, x - first - second);
        cout << char('a' + first - 1) << char('a' + second - 1) << char('a' + third - 1) << endl;
    }
    return 0;
}