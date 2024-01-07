#include <iostream>
#include <stack>
using namespace std; // Print middle element of a stack
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void MiddleEle(stack<int> &s, int size, int count)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    MiddleEle(s, size, count + 1);
    s.push(num);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    print(s);
    MiddleEle(s, s.size(), 0);
    print(s);
    return 0;
}