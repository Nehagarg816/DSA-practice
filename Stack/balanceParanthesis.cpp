#include <iostream>
#include <stack>
using namespace std; // Check for balanced parenthesis
bool balanceBracket(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        if (s[i] == ')')
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
        if (s[i] == '}')
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
        if (s[i] == ']')
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
    return false;
}
int main()
{
    string s = "[{()}]";
    if (balanceBracket(s))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}