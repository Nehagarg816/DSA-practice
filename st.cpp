#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> st1;
    stack<int> st2;

    void push(int ele)
    {
        st1.push(ele);
    }
    int pop(void)
    {
        if (!st2.empty())
        {
            int ele = st2.top();
            st2.pop();
            return ele;
        }
        else
        {
            while (st2.empty() && !st1.empty())
            {
                int ele = st1.top();
                st1.pop();
                st2.push(ele);
            }
            int elem = st2.top();
            st2.pop();
            return elem;
        }
    }
    int isEmpty(void)
    {
        if (st1.empty() and st2.empty())
            return 1;
        else
            return 0;
    }
};

int main()
{
    Queue q;
    q.push(4);
    q.push(40);
    q.push(47);
    q.push(400);
    q.push(45);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}