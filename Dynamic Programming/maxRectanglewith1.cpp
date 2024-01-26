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
int maximalRectangle(vector<vector<char>> &matrix)
{
    int ans = INT_MIN;
    vector<int> heights(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < heights.size(); j++)
        {
            if (matrix[i][j] == '1')
            {
                heights[j]++;
            }
            else
            {
                heights[j] = 0;
            }
        }
        ans = max(ans, largestArea(heights));
    }
    return ans;
}
int main()
{
    vector<vector<char>> matrix;
    matrix.push_back({'1', '0', '1', '0', '0'});
    matrix.push_back({'1', '0', '1', '1', '1'});
    matrix.push_back({'1', '1', '1', '1', '1'});
    matrix.push_back({'1', '0', '0', '1', '0'});
    cout << maximalRectangle(matrix);
    return 0;
}