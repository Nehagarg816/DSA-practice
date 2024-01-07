#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10); // pushing elements in stack
    s.push(20);
    cout << s.size() << endl;
    s.pop();                  // popping elements from stack
    cout << s.size() << endl; // size of stack
    cout << s.top() << endl;  // top of stack
    s.pop();
    if (s.empty()) // checking if stack is empty or not
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    s, push(30);
    s.push(40);
    s.peek(); // peeking elements from stack

    return 0;
}