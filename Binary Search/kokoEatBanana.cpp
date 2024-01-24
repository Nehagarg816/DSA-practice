#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long timetaken(vector<int> &piles, int k)
{
    long long time = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        time += (piles[i] / k) + ((piles[i] % k == 0) ? 0 : 1);
    }
    return time;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (timetaken(piles, mid) <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> piles;
    piles.push_back(3);
    piles.push_back(7);
    piles.push_back(11);
    piles.push_back(7);
    cout << minEatingSpeed(piles, 8);
    return 0;
}