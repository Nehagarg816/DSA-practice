#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int n, vector<int> &arr, int q, vector<vector<int>> &queries)
{
    vector<int> temp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        temp[i] = temp[i - 1] | arr[i - 1];
    }
    vector<int> ans;
    for (auto q : queries)
    {
        int index = q[0];
        int val = q[1];
        int l = index, r = n;
        if (index == n)
        {
            if (arr[index - 1] >= val)
            {
                ans.push_back(index);
            }
            else
            {
                ans.push_back(-1);
            }
            continue;
        }
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if ((temp[mid] | temp[index - 1]) >= val)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if ((temp[l] | temp[index - 1]) >= val)
        {
            ans.push_back(l);
        }
        else
        {
            ans.push_back(-1);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int q;
    cin >> q;
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        queries.push_back({x, y});
    }
    vector<int> ans = solve(n, arr, q, queries);
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}