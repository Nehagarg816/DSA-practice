// #include <bits/stdc++.h>
// using namespace std;
// string solve(int k)
// {
//     string s = "";
//     while (k > 0)
//     {
//         if (k & 1)
//         {
//             s += '1';
//         }
//         else
//         {
//             s += '0';
//         }
//         k /= 2;
//     }
//     return s;
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         string s = solve(k);
//         vector<int> ans;
//         for (int i = s.length() - 1; i >= 0; i--)
//         {
//             if (n == 1)
//             {
//                 int a = 0;
//                 while (i >= 0)
//                 {
//                     if (s[i] == '1')
//                         a += pow(2, i);
//                     i--;
//                 }
//                 ans.push_back(a);
//                 n--;
//             }
//             else
//             {
//                 int b = pow(2, i);
//                 if (s[i] == '1')
//                 {
//                     ans.push_back(b);
//                     n--;
//                 }
//             }
//             if (n == 0)
//             {
//                 break;
//             }
//         }
//         while (n > 0)
//         {
//             ans.push_back(0);
//             n--;
//         }
//         for (int x : ans)
//         {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << k << endl;
            continue;
        }
        int a = 0;
        int b = 1;
        while (a + b <= k)
        {
            a += b;
            b <<= 1;
        }
        cout << a << " " << k - a << " ";
        n -= 2;
        while (n--)
        {
            cout << 0 << " ";
        }
        cout << endl;
    }
}