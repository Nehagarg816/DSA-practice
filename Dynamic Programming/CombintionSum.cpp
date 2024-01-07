#include <iostream>
#include <vector>
using namespace std;
void solve(vector<vector<int>> &ans, vector<int> &candidates, int index, int target)
{
    if (target == 0)
    {
        ans.push_back(candidates);
    }
    for (int i = index; i < candidates.size(); ++i)
    {
        if (target >= candidates[i])
        {
            vector<int> tmp(candidates.begin() + index, candidates.begin() + i + 1);
            tmp.erase(tmp.begin() + i + 1 - index, tmp.end());
            solve(ans, tmp, i, target - candidates[i]);
        }
        else
            break;
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    int n = candidates.size();
    if (target < candidates[0])
    {
        return {};
    }
    sort(candidates.begin(), candidates.end());
    solve(ans, candidates, 0, target);
    return ans;
}
int main()
{
    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
    int target = 3;
    vector<vector<int>> res;
    res = combinationSum(candidates, target);
    for (int i = 0; i < res, size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
        {
            cout << res[i][j] << " ";
        }
    }
    return 0;
}