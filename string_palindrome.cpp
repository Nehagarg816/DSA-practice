#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    int p = s.size();
    for (int i = 0; i < p / 2; i++)
    {
        if (s[i] != s[p - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "ana";
    if (isPalindrome(s))
    {
        cout << "The string " << s << " is a palindrome";
    }
    else
    {
        cout << "The string " << s << " is not a palindrome";
    }
    return 0;
}