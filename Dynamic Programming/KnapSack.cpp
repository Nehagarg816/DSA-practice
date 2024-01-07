#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> weight, vector<int> value, int index, int capacity)
{
    // Base case
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }
    int ans = 0;
    int incl = 0;
    int excl = 0;
    if (weight[index] <= capacity)
    {
        incl = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }
    excl = 0 + solve(weight, value, index - 1, capacity);
    ans = max(incl, excl);
    return ans;
}
int solveMemo(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>> dp)
{
    // Base case
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    int ans = 0;
    int incl = 0;
    int excl = 0;
    if (weight[index] <= capacity)
    {
        incl = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }
    excl = 0 + solve(weight, value, index - 1, capacity);
    ans = max(incl, excl);
    dp[index][capacity] = ans;
    return dp[index][capacity];
}
int solveTab(vector<int> weight, vector<int> value, int index, int capacity)
{
    vector<vector<int>> dp(index, vector<int>(capacity + 1, 0));
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[w] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int incl = 0;
            if (weight[i] <= j)
            {
                incl = value[i] + dp[i - 1][j - weight[i]];
            }
            int excl = 0 + dp[i - 1][j];
            dp[i][j] = max(incl, excl);
        }
    }
    return dp[index - 1][capacity];
}
int solveSpace1(vector<int> weight, vector<int> value, int index, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[w] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int incl = 0;
            if (weight[i] <= j)
            {
                incl = value[i] + prev[j - weight[i]];
            }
            int excl = 0 + prev[j];
            curr[j] = max(incl, excl);
        }
        prev = curr;
    }
    return prev[capacity];
}
int solveSpace2(vector<int> weight, vector<int> value, int index, int capacity)
{
    vector<int> curr(capacity + 1, 0);
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[w] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }
    for (int i = 1; i < index; i++)
    {
        for (int j = capacity; j >= 0; j--)
        {
            int incl = 0;
            if (weight[i] <= j)
            {
                incl = value[i] + curr[j - weight[i]];
            }
            int excl = 0 + curr[j];
            curr[j] = max(incl, excl);
        }
    }
    return curr[capacity];
}
int main()
{
    vector<int> weight;
    vector<int> value;
    weight.push_back(1);
    weight.push_back(2);
    weight.push_back(4);
    weight.push_back(5);
    value.push_back(5);
    value.push_back(4);
    value.push_back(8);
    value.push_back(6);
    int maxWeight = 5;
    int n = 4;
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    cout << solve(weight, value, n - 1, maxWeight) << endl;         // Recursion
    cout << solveMemo(weight, value, n - 1, maxWeight, dp) << endl; // Recursion + Memoization
    cout << solveTab(weight, value, n - 1, maxWeight) << endl;      // Tabulation
    cout << solveSpace1(weight, value, n - 1, maxWeight) << endl;   // Space Optimization
    cout << solveSpace2(weight, value, n - 1, maxWeight) << endl;   // Space Optimization with curr array only
    return 0;
}