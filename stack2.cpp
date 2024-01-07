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
            cout << d << " ";
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop() // Popping elements from stack
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
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
};
int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
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

    return 0;
}