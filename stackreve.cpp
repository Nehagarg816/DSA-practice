#include <iostream>
#include <stack>
using namespace std; // stack reversal without using any extra space
void insert_at_bottom(stack<int> &st, int x)
{
    if (st.size() == 0)
    {
        st.push(x);
    }
    else
    {
        int y = st.top();
        st.pop();
        insert_at_bottom(st, x);
        st.push(y);
    }
}
void reverseStack(stack<int> &st)
{
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();
        reverseStack(st);
        insert_at_bottom(st, x);
    }
    return;
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    print(s);
    reverseStack(s);
    print(s);
    return 0;
}