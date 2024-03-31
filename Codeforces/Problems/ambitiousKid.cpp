#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mini = INT_MAX;
    for (int x : a)
    {
        mini = min(mini, abs(x));
    }
    cout << abs(mini) << endl;
}