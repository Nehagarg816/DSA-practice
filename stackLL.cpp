#include <iostream>
using namespace std; // Stack implementation using Linked List
class Node           // class for LL
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
class Stack // class for stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void print() // print the LL elements in stack
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
        }

        Node *curr = top;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void push(int d) // pushing the elements
    {
        Node *temp = new Node(d);
        if (top == NULL)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
        cout << d << " is pushed in the stack" << endl;
    }
    int peek() // top element of stack
    {
        return top->data;
    }
    void pop() // popping the elements
    {
        cout << peek() << " is popped from the stack" << endl;
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
        }
        if (top->next == NULL)
        {
            top = NULL;
        }
        else
        {
            Node *curr = top;
            top = curr->next;
            curr->next = NULL;
        }
    }
    bool isEmpty() // checking if the stack is empty or not
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Size() // size of stack
    {
        Node *curr = top;
        int s = 0;
        while (curr != NULL)
        {
            s++;
            curr = curr->next;
        }
        return s;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout << "Peek element in the stack is " << s.peek() << endl;
    s.pop();
    s.print();
    s.pop();
    s.print();
    cout << s.peek() << endl;
    if (s.isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }
    cout << "Size of the stack is " << s.Size() << endl;
    return 0;
}