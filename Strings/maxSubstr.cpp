#include <iostream>
#include <bits\stdc++.h>
using namespace std;
bool isPalindrome(string &str, int s, int e)
{
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}
string longestPalindrome(string s)
{
    int start = 0;
    int n = s.length();
    int maxi = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j))
            {
                if (maxi < j - i + 1)
                {
                    maxi = j - i + 1;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxi);
}
int main()
{
    string s = "aba";
    cout << longestPalindrome(s);
    return 0;
}