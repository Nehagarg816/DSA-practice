#include <bits/stdc++.h>
using namespace std;
void solve(int &op, int &minus_one, int &one)
{
    op++;
    minus_one--;
    one++;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int minus_one = 0;
        int one = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
            {
                one++;
            }
            else
            {
                minus_one++;
            }
        }
        int op = 0;
        while (minus_one % 2 != 0 or minus_one > one)
        {
            solve(op, minus_one, one);
        }
        cout << op << endl;
    }
}