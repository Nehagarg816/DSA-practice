#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({2, 6});
    intervals.push_back({8, 10});
    intervals.push_back({15, 18});
    intervals.push_back({16, 30});
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}