#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> arr;
        arr.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] >= a[i - 1])
            {
                arr.push_back(a[i]);
            }
            else
            {
                arr.push_back(a[i]);
                arr.push_back(a[i]);
            }
        }
        cout << arr.size() << endl;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}