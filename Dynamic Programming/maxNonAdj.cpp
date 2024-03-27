#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }
    int incl = solve(arr, n - 2) + arr[n];
    int excl = solve(arr, n - 1) + 0;
    int ans = max(incl, excl);
    return ans;
}
int solveMemo(vector<int> &arr, int n, vector<int> dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int incl = solveMemo(arr, n - 2, dp) + arr[n];
    int excl = solveMemo(arr, n - 1, dp) + 0;
    dp[n] = max(incl, excl);
    return dp[n];
}
int solveTab(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int incl = dp[i - 2] + arr[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}
int solveSpace(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    int prev2 = 0;
    int prev1 = arr[0];
    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + arr[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int main()
{
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(9);
    arr.push_back(8);
    arr.push_back(2);
    int n = arr.size() - 1;
    vector<int> dp(n + 1, -1);
    cout << solve(arr, n) << endl;
    cout << solveMemo(arr, n, dp) << endl;
    cout << solveTab(arr) << endl;
    cout << solveSpace(arr);
    return 0;
}
