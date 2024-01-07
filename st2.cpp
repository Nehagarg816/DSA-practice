#include <iostream>
#include <queue>
using namespace std;

class Stack
{

public:
    queue<int> q1;
    void push(int ele)
    {
        q1.push(ele);
        for (int i = 0; i < q1.size() - 1; i++)
        {

            int element = q1.front();
            q1.pop();
            q1.push(element);
        }
    }
    void pop(void)
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        q1.pop();
    }
    int front(void)
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};

int main()
{
    /*code*/

    Stack s1;
    s1.push(22);
    s1.push(20);
    s1.push(29);
    s1.push(25);
    s1.push(2);
    s1.push(332);
    cout << s1.front() << endl;
    s1.pop();
    cout << s1.front() << endl;
    s1.pop();
    cout << s1.front() << endl;
    s1.pop();
    cout << s1.front() << endl;
    s1.pop();
    cout << s1.front() << endl;
    s1.pop();
    s1.push(22);
    cout << s1.front() << endl;

    return 0;
}