#include <iostream>
#include <vector>
using namespace std; // Fibonacci Series

int fib3(int n) // TC:O(n)and SC:O(1)
{
    int prev1 = 0;
    int prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = (prev1 + prev2) % 1000000007;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
int fib2(int n, vector<int> &dp) // TC:O(n)and SC:O(n)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int fib(int n, vector<int> &dp) // TC:O(n)and SC:O(n)+O(n)=O(n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << fib(n, dp) << endl;  // Top-Down Approach: Recursion + Memoization
    cout << fib2(n, dp) << endl; // Bottom-Up Approach: Tabulation
    cout << fib3(n) << endl;     // Space Optimisation Technique
    return 0;
}