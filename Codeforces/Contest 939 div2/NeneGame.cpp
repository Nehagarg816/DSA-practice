#include <bits/stdc++.h>
using namespace std;
void count(int k, int q)
{
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    int x = arr[0];
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        if (n >= x)
            cout << x - 1 << " ";
        else
            cout << n << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, q;
        cin >> k >> q;
        count(k, q);
    }
    cout << endl;
}
