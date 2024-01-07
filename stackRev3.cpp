#include <iostream>
#include <stack>
using namespace std; // Reverse a stack
void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void InsertAtBottom(stack<int> &sta, int x)
{
    if (sta.empty())
    {
        sta.push(x);
        return;
    }
    int num = sta.top();
    sta.pop();
    InsertAtBottom(sta, x);
    sta.push(num);
}
void Reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    Reverse(s);
    InsertAtBottom(s, num);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    print(s);
    Reverse(s);
    print(s);
    return 0;
}