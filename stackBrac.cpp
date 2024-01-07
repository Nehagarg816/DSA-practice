#include <iostream>
#include <stack>
using namespace std; // Valid Brackets
bool ValidBracket(string st)
{
    stack<char> s;
    char ch;
    for (int i = 0; i < st.length(); i++)
    {
        ch = st[i];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if (ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s;
    s = {"{[()]}"};
    cout << ValidBracket(s) << endl;
    string s2 = {"[){}(]"};
    cout << ValidBracket(s2) << endl;
    return 0;
}