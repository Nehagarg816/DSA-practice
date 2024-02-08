#include <bits/stdc++.h>
using namespace std;
bool solve(int n, int m, int k, vector<int> &arr1, vector<int> &arr2)
{
    vector<int> a;
    int k1 = 1;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] == k1 and k1 <= k and count1 <= k / 2)
        {
            a.push_back(i);
            k1++;
            count1++;
        }
    }
    int k2 = 1;
    for (int i = 0; i < m; i++)
    {
        if (arr2[i] == k2 and k2 <= k and count2 <= k / 2)
        {
            a.push_back(i);
            k2++;
            count2++;
        }
    }
    sort(a.begin(), a.end());
    int k3 = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == k3)
        {
            k3++;
        }
    }
    return (k3 > k);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr1(n);
        vector<int> arr2(m);
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        if (solve(n, m, k, arr1, arr2))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}