#include <iostream>
#include <stack>
using namespace std; // Reverse a stack
void print(stack<char> c)
{
    while (!c.empty())
    {
        cout << c.top();
        c.pop();
    }
    cout << endl;
}
int main()
{
    stack<char> ch;
    ch.push('a');
    ch.push('h');
    ch.push('e');
    ch.push('n');
    ch.push(' ');
    ch.push('g');
    ch.push('r');
    ch.push('a');
    ch.push('g');
    print(ch);
    // char cha = 23;
    // for (int i = 0; i < 50; i++)
    // {
    //     char cha = 23 + i;
    //     cout << cha << endl;
    // }

    return 0;
}