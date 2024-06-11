#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        char x = a[0];
        a[0] = b[0];
        b[0] = x;
        cout << a << " " << b << endl;
    }
}