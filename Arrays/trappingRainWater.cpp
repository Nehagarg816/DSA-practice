#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }
    int water_trapped = 0;
    for (int i = 0; i < n; i++)
    {
        water_trapped += min(left[i], right[i]) - height[i];
    }
    return water_trapped;
}
int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);
    return 0;
}