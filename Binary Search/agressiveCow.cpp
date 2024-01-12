#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Aggressive Cow Problem
bool isPossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int last = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            last = stalls[i];
        }
    }
    return false;
}
int aggressiveCow(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int ans = 0;
    int e = maxi;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> stalls;
    int k = 2;
    stalls.push_back(4);
    stalls.push_back(2);
    stalls.push_back(1);
    stalls.push_back(3);
    stalls.push_back(6);
    cout << aggressiveCow(stalls, k);
    return 0;
}