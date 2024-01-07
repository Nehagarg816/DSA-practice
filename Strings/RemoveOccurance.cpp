#include <iostream>
#include <string>
using namespace std;
string RemoveOccurrence(string &s, string &part)
{
    while (s.find(part) < s.length() and s.length() > 0)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    RemoveOccurrence(s, part);
    cout << s;
    return 0;
}