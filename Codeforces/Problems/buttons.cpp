#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
        {
            cout << "FIRST" << endl;
        }
        else if (b > a)
        {
            cout << "SECOND" << endl;
        }
        else if (c & 1)
        {
            cout << "FIRST" << endl;
        }
        else
        {
            cout << "SECOND" << endl;
        }
    }
}