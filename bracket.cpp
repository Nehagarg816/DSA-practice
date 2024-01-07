#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool validParenthesis(string s)
{
    if (s.empty())
    {
        return true;
    }
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
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
    string s = "{}";
    bool p = validParenthesis(s);
    if (p)
    {
        cout << "Valid Parenthesis" << endl;
    }
    else
    {
        cout << "Invalid Parenthesis" << endl;
    }
    return 0;
}