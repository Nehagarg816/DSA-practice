#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> candidates, int target)
{
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < candidates.size(); i++)
    {
        ans += solve(candidates, target - candidates[i]);
    }
    return ans;
}
int solveMemo(vector<int> candidates, int target, vector<int> dp)
{
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }
    int ans = 0;
    for (int i = 0; i < candidates.size(); i++)
    {
        ans += solve(candidates, target - candidates[i]);
    }
    dp[target] = ans;
    return dp[target];
}
int solveTab(vector<int> candidates, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < candidates.size(); j++)
        {
            if (i - candidates[j] >= 0 and dp[i - candidates[j]] != -1)
            {
                dp[i] += dp[i - candidates[j]];
            }
        }
    }
    return dp[target];
}
int main()
{
    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
    int target = 3;
    vector<int> dp(target + 1, -1);
    cout << solve(candidates, target) << endl;
    cout << solveMemo(candidates, target, dp) << endl;
    cout << solveTab(candidates, target) << endl;
    return 0;
}