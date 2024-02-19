#include <bits/stdc++.h>
using namespace std;
int solve(int p, vector<int> &id, vector<int> &bids)
{
    int n = id.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[id[i]].push_back(bids[i]);
    }
    int ans = 0;
    for (auto x : m)
    {
        sort(x.second.begin(), x.second.end());
        ans += x.second[0];
    }
    return ans;
}
int main()
{
    int p = 3;
    vector<int> projectID = {2, 0, 1, 2};
    vector<int> bids = {8, 7, 6, 9};
    cout << solve(p, projectID, bids) << endl;
}