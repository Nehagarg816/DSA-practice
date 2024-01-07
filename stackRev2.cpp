#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void InsertAtBottom(stack<int> &sta, int x) // Insert element at bottom of stack
{
    if (sta.empty())
    {
        sta.push(x);
        return;
    }
    int n = sta.top();
    sta.pop();
    InsertAtBottom(sta, x);
    sta.push(n);
}
void ReverseRec(stack<int> &st) // Reverse a stack using recursion
{
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    ReverseRec(st);
    InsertAtBottom(st, num);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    print(s);
    ReverseRec(s);
    print(s);
    return 0;
}