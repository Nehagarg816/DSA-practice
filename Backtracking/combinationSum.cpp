#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void solve(int k, int target, vector<int> &way, int index)
{
    if (k == 0)
    {
        if (target == 0)
        {
            ans.push_back(way);
            return;
        }
    }
    for (int i = index; i <= 9; i++)
    {
        way.push_back(i);
        solve(k - 1, target - i, way, i + 1);
        way.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> way;
    solve(k, n, way, 1);
    return ans;
}
int main()
{
    int k = 3;
    int n = 7;
    vector<vector<int>> ans = combinationSum3(k, n);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}