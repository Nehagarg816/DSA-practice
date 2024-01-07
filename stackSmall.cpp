#include <iostream>
#include <vector>
#include <stack>
using namespace std; // Next Smaller Element
void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
vector<int> NextSmallElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr = {4, 5, 2, 10, 8};
    print(arr);
    int n = arr.size();
    vector<int> answer = NextSmallElement(arr, n);
    print(answer);
    return 0;
}