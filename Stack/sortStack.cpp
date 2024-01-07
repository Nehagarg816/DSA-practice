#include <iostream>
#include <stack>
using namespace std; // Sort a Stack
void sortStack(stack<int> &s)
{
    stack<int> st;
    while (!s.empty())
    {
        int ele = s.top();
        s.pop();
        while (!st.empty() and st.top() < ele)
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
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(4);
    s.push(3);
    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}