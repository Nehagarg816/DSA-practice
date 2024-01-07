#include <iostream>
#include <stack>
using namespace std; // Redundant Brackets
bool RedundantBracket(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;
                char top = st.top();
                while (st.top() != '(')
                {
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str;
    str = "(a+b)";
    if (RedundantBracket(str))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}