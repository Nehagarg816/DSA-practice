#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        vector<vector<char>> v(2 * a, vector<char>(2 * a, ' '));
        bool flag2 = 1;
        int i = 0;
        while (i < 2 * a)
        {
            bool flag = flag2;
            for (int j = 0; j < 2 * a; j++)
            {
                if (flag == 1)
                {
                    v[i][j] = '#';
                }
                else
                {
                    v[i][j] = '.';
                }
                if (j % 2 != 0)
                {
                    flag = (flag == 1 ? 0 : 1);
                }
            }
            i++;
            if (i % 2 == 0)
            {
                flag2 = (flag2 == 1) ? 0 : 1;
            }
        }
        for (int i = 0; i < 2 * a; i++)
        {
            for (int j = 0; j < 2 * a; j++)
            {
                cout << v[i][j];
            }
            cout << endl;
        }
    }
}