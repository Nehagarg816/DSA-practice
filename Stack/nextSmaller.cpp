#include <iostream>
#include <stack>
#include <vector>
using namespace std; // Next Smaller element in an array
void nextSmaller(vector<int> arr, vector<int> &ans)
{
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() and arr[i] < s.top())
        {
            s.pop();
        }
        if (!s.empty())
        {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    int n = arr.size();
    vector<int> ans(n, -1);
    nextSmaller(arr, ans);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}