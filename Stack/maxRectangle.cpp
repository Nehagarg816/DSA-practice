#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &heights, int n)
{
    vector<int> ans(n, 0);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 and heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &heights, int n)
{
    vector<int> ans(n, 0);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 and heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int length = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;
        int newArea = length * breadth;
        area = max(area, newArea);
    }
    return area;
}
int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    cout << largestArea(heights);
    return 0;
}