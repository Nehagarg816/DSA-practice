#include <iostream>
#include <stack>
using namespace std;

void insertAtBootom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBootom(st, ele);
    st.push(topele);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBootom(st, ele);
}

int main()
{
    stack<int> st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    reverse(st);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    return 0;
}