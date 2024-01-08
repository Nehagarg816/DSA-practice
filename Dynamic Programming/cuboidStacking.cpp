#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std; // Maximum height by stacking cuboids
bool check(vector<int> b, vector<int> a)
{
    if (a[0] <= b[0] and a[2] <= b[2] and a[1] <= b[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solveSO(vector<vector<int>> &nums, int n)
{
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int current = n - 1; current >= 0; current--)
    {
        for (int prev = current - 1; prev >= -1; prev--)
        {
            int incl = 0;
            if (prev == -1 or check(nums[current], nums[prev]))
            {
                incl = nums[current][2] + next[current + 1];
            }
            int excl = 0 + next[prev + 1];
            curr[prev + 1] = max(incl, excl);
        }
        next = curr;
    }
    return next[0];
}
int cuboidStacking(vector<vector<int>> &cuboids)
{
    // sort all dimension for every cuboid
    int n = cuboids.size();
    for (auto &cub : cuboids)
    {
        sort(cub.begin(), cub.end());
    }
    // sort cuboids on the basis of width
    sort(cuboids.begin(), cuboids.end());
    // use logic of LIS
    return solveSO(cuboids, n);
}
int main()
{
    vector<vector<int>> cuboids;
    cuboids.push_back({50, 45, 20});
    cuboids.push_back({95, 37, 53});
    cuboids.push_back({45, 23, 12});
    cout << cuboidStacking(cuboids);
    return 0;
}