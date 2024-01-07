#include <iostream>
#include <stack>
using namespace std; // Sort a stack
void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void SortedStack(stack<int> &st, int x)
{
    if (st.empty() || (!st.empty() && st.top() < x))
    {
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    SortedStack(st, x);
    st.push(num);
}
void SortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    SortStack(st);
    SortedStack(st, num);
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    print(s);
    SortStack(s);
    print(s);
    return 0;
}