#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        long long ans = 0;
        set<long long> s;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            s.insert(a[i]);
            sum += a[i];

            long long maxi = *(--s.end());
            if (maxi == (sum - maxi))
            {
                ans += 1;
            }
        }

        cout << ans << endl;
    }
}
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<long long> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         vector<long long> p(n, 0);
//         p[0] = a[0];
//         for (int i = 1; i < n; i++)
//         {
//             p[i] = p[i - 1] + a[i];
//         }
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (p[i] - a[j] == a[j])
//                 {
//                     count++;
//                     break;
//                 }
//             }
//         }
//         cout << count;
//     }
// }