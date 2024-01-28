#include <bits/stdc++.h>
using namespace std;
vector<long long> div(long long n)
{
    vector<long long> vec;
    vec.push_back(1);
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            vec.push_back(i);
            vec.push_back(n / i);
        }
    }
    vec.push_back(n);
    return vec;
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> vec;
    vec = div(n);
    sort(vec.begin(), vec.end());
    long long ans = 0;
    for (int i : vec)
    {
        if (i * m <= n)
        {
            ans = i;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }
    return 0;
}