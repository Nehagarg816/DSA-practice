#include <iostream>
#include <stack>
using namespace std; // Insert at bottom of stack
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void InsertAtBottom(stack<int> &st, int num)
{
    if (st.empty())
    {
        st.push(num);
        return;
    }
    int n = st.top();
    st.pop();
    InsertAtBottom(st, num);
    st.push(n);
}
int main()
{
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    print(s);
    InsertAtBottom(s, 1);
    print(s);
    return 0;
}