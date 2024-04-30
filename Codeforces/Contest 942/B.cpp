// #include <bits/stdc++.h>
// using namespace std;
// int solve(string &s, bool &flag)
// {
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s.length() == 1)
//         {
//             return (s == "U" ? 1 : 0);
//         }
//         if (s.length() == 2)
//         {
//             s.erase(0, 1);
//             if (s == "U")
//             {
//                 return 1;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         if (s[i] == 'U')
//         {
//             if (i == 0)
//             {
//                 s[i + 1] = (s[i + 1] == 'D' ? 'U' : 'D');
//             }
//             else if (i == s.length() - 1)
//             {
//                 s[i - 1] = (s[i - 1] == 'D' ? 'U' : 'D');
//             }
//             else
//             {
//                 s[i - 1] = (s[i - 1] == 'D' ? 'U' : 'D');
//                 s[i + 1] = (s[i + 1] == 'D' ? 'U' : 'D');
//             }
//             s.erase(i, 1);
//             flag = (flag == false ? true : false);
//             i--;
//         }
//     }
//     if (flag == true and s == "U")
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         bool flag = false;
//         int ans = solve(s, flag);
//         if (ans == 1)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int solve(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.length() == 1)
        {
            return (s == "U" ? 1 : 0);
        }
        if (s.length() == 2)
        {
            s.erase(0, 1); // Removes the first character
            return (s == "U" ? 1 : 0);
        }

        if (s[i] == 'U') // If you find a 'U', manipulate neighbors
        {
            if (i > 0) // Ensure you don't go out of bounds
            {
                s[i - 1] = (s[i - 1] == 'D' ? 'U' : 'D');
            }
            if (i < s.length() - 1)
            {
                s[i + 1] = (s[i + 1] == 'D' ? 'U' : 'D');
            }

            s.erase(i, 1); // Erase the current 'U'
            i--;           // Avoid skipping over an element
        }
    }

    return (s == "U" ? 1 : 0); // Return 1 if ends with 'U', 0 otherwise
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = solve(s);                        // No need for flag
        cout << (ans == 1 ? "YES" : "NO") << endl; // Output result based on the final state of 's'
    }
}
