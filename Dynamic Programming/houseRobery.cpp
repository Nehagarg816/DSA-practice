#include <iostream>
#include <vector>
using namespace std; // House Robery
int solveSpace(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    int prev2 = 0;
    int prev1 = arr[0];
    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + arr[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(3);
    arr.push_back(1);
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            first.push_back(arr[i]);
        }
        if (i != 0)
        {
            second.push_back(arr[i]);
        }
    }
    cout << solveSpace(first) << endl;
    cout << solveSpace(second) << endl;
    int ans = max(solveSpace(first), solveSpace(second));
    cout << ans;
    return 0;
}