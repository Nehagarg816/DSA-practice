#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> s(11, vector<char>(11));
        int sum = 0;
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                cin >> s[i][j];
                if (s[i][j] == 'X')
                {
                    if ((i == 1 or i == 10) or (j == 1 or j == 10))
                    {
                        sum += 1;
                    }
                    else if ((i == 2 or i == 9) or (j == 2 or j == 9))
                    {
                        sum += 2;
                    }
                    else if ((i == 3 or i == 8) or (j == 3 or j == 8))
                    {
                        sum += 3;
                    }
                    else if ((i == 4 or i == 7) or (j == 4 or j == 7))
                    {
                        sum += 4;
                    }
                    else if ((i == 5 or i == 6) or (j == 5 or j == 6))
                    {
                        sum += 5;
                    }
                }
            }
        }
        cout << sum << endl;
    }
}