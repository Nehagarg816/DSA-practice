#include <iostream>
using namespace std; // Stack implementation using array
class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int s)
    {
        this->size = s;
        this->top = -1;
        this->arr = new int[s];
    }
    void push(int d) // Pushing elements in stack
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = d;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
        cout << d << " is pushed in the stack" << endl;
    }
    int peek() // Top of stack
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    void pop() // Popping elements from stack
    {
        cout << peek() << " is popped from the stack" << endl;
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty() // Checking if stack is empty or not
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};
int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.print();
    st.pop();
    cout << st.peek() << endl;
    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    if (st.isFull())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }
    return 0;
}