#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solution(int n, int m, vector<vector<char>> mat)
{
    int MOD = 1000000007;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: There is only one way to reach (1, 1)
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mat[i - 1][j - 1] == 'X')
            {
                // If there's a monster at (i, j), set dp[i][j] to 0
                dp[i][j] = 0;
            }
            else
            {
                // Calculate the number of ways to reach (i, j) without monsters
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    return dp[n][m];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << solution(n, m, mat);
    return 0;
}