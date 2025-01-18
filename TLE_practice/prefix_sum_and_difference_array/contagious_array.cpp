#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    map<int, int> m;
    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            sum -= 1;
        else
            sum += 1;
        if (sum == 0)
            ans = i + 1;
        else
        {
            if (m.find(sum) != m.end())
                ans = max(ans, i - m[sum]);
            else
                m[sum] = i;
        }
    }
    cout << ans;
    return 0;
}