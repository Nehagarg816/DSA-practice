#include <iostream>
#include <stack>
using namespace std;
stack<int> reverse(stack<int> &s)
{
    stack<int> st;
    while (!s.empty())
    {
        int ele = s.top();
        s.pop();
        if (!st.empty() and s.top() < st.top())
        {
            s.push(st.top());
            st.pop();
        }
        st.push(ele);
    }
    while (!st.empty())
    {
        s.push(st.top());
        st.pop();
    }
    return s;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(4);
    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}