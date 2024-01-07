#include <iostream>
#include <vector>
using namespace std; // Largest Square
int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
{
    if (i >= mat.size() or j >= mat[0].size())
    {
        return 0;
    }
    int right = solve(mat, i, j + 1, maxi);
    int diagonal = solve(mat, i + 1, j + 1, maxi);
    int down = solve(mat, i + 1, j, maxi);
    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return maxi;
    }
    else
    {
        return 0;
    }
}
int solveMemo(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= mat.size() or j >= mat[0].size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = solveMemo(mat, i, j + 1, maxi, dp);
    int diagonal = solveMemo(mat, i + 1, j + 1, maxi, dp);
    int down = solveMemo(mat, i + 1, j, maxi, dp);
    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        dp[i][j] = maxi;
        return dp[i][j];
    }
    else
    {
        return 0;
    }
}
int solveTab(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = (j + 1 < col) ? dp[i][j + 1] : 0;
            int diagonal = (i + 1 < row && j + 1 < col) ? dp[i + 1][j + 1] : 0;
            int down = (i + 1 < row) ? dp[i + 1][j] : 0;

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}
int solveSO(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<int> curr(col + 1, 0);
    vector<int> next(col + 1, 0);
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = (j + 1 < col) ? curr[j + 1] : 0;
            int diagonal = (i + 1 < row && j + 1 < col) ? next[j + 1] : 0;
            int down = (i + 1 < row) ? next[j] : 0;

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return maxi;
}
int main()
{
    vector<vector<int>> mat;
    // mat.push_back({1, 0, 1, 0, 0});
    // mat.push_back({1, 0, 1, 1, 1});
    // mat.push_back({1, 1, 1, 1, 1});
    // mat.push_back({1, 0, 0, 0, 0});
    mat.push_back({1, 1});
    mat.push_back({1, 1});
    int maxi = 0;
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << solve(mat, 0, 0, maxi) << endl;
    // cout << solveMemo(mat, 0, 0, maxi, dp) << endl;
    cout << solveTab(mat, maxi) << endl;
    cout << solveSO(mat, maxi) << endl;
    return 0;
}