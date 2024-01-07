#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std; // Minimum cost for Tickets
int solve(vector<int> &days, vector<int> &costs, int index)
{
    int ans = INT_MAX;
    if (index >= days.size())
    {
        return 0;
    }
    int i;
    int option1 = costs[0] + solve(days, costs, index + 1);
    for (i = 0; i < days.size() and days[i] < (days[index] + 7); i++)
        ;
    int option2 = costs[1] + solve(days, costs, i);
    for (i = 0; i < days.size() and days[i] < (days[index] + 30); i++)
        ;
    int option3 = costs[2] + solve(days, costs, i);
    ans = min(option1, min(option2, option3));
    return ans;
}
int solveMemo(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    int ans = INT_MAX;
    if (index >= days.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int i;
    int option1 = costs[0] + solve(days, costs, index + 1);
    for (i = 0; i < days.size() and days[i] < (days[index] + 7); i++)
        ;
    int option2 = costs[1] + solve(days, costs, i);
    for (i = 0; i < days.size() and days[i] < (days[index] + 30); i++)
        ;
    int option3 = costs[2] + solve(days, costs, i);
    ans = min(option1, min(option2, option3));
    dp[index] = ans;
    return dp[index];
}
int solveTab(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int k = n - 1; k >= 0; k--)
    {
        int i;
        int option1 = costs[0] + dp[k + 1];
        for (i = 0; i < days.size() and days[i] < (days[k] + 7); i++)
            ;
        int option2 = costs[1] + dp[i];
        for (i = 0; i < days.size() and days[i] < (days[k] + 30); i++)
            ;
        int option3 = costs[2] + dp[i];
        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}
int main()
{
    vector<int> days;
    vector<int> costs;
    days.push_back(2);
    days.push_back(5);
    costs.push_back(1);
    costs.push_back(4);
    costs.push_back(25);
    int n = days.size();
    vector<int> dp(n, -1);
    cout << solve(days, costs, 0) << endl;
    cout << solveMemo(days, costs, 0, dp) << endl;
    cout << solveTab(days, costs) << endl;
    return 0;
}