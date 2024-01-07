#include <iostream>
using namespace std; // Implementing two stacks in an array
class Stack
{
public:
    int top1;
    int top2;
    int *arr;
    int size;
    Stack(int s)
    {
        this->size = s;
        this->top1 = -1;
        this->top2 = size;
        this->arr = new int[s];
    }
    void print() // Printing elements of stack
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void push1(int d) // Pushing elements in stack1
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = d;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void push2(int d2) // Pushing elements in stack2
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = d2;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop1() // Popping elements from stack1
    {
        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    void pop2() // Popping elements from stack2
    {
        if (top2 < size)
        {
            top2++;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
};
int main()
{
    Stack s(5);
    s.push1(10);
    s.push1(20);
    // s.print();
    s.push2(30);
    s.push2(40);
    s.push2(50);
    s.print();
    s.pop1();
    s.pop2();
    s.print();
    return 0;
}