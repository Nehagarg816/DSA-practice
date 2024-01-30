#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool solve2(int n, int k, vector<int> &nums, int i)
{
    if (is_sorted(nums.begin(), nums.end()) or k > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        cout << (solve2(n, k, nums, 0) ? "YES" : "NO") << endl;
        t--;
    }
    return 0;
}