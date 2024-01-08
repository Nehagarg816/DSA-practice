#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std; // Russian Doll Envelope Problem
static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
int solveOptimal(vector<int> &heights, int n)
{
    if (n == 0)
    {
        return 0;
    }
    vector<int> ans;
    ans.push_back(heights[0]);
    for (int i = 1; i < n; i++)
    {
        if (heights[i] > ans.back())
        {
            ans.push_back(heights[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
            ans[index] = heights[i];
        }
    }
    return ans.size();
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> heights;
    for (int i = 0; i < envelopes.size(); i++)
    {
        heights.push_back(envelopes[i][1]);
    }
    int n = heights.size();
    return solveOptimal(heights, n);
}
int main()
{
    vector<vector<int>> envelopes;
    envelopes.push_back({5, 4});
    envelopes.push_back({6, 4});
    envelopes.push_back({6, 7});
    envelopes.push_back({2, 3});
    cout << maxEnvelopes(envelopes);
    return 0;
}