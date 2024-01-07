#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int item)
{
    if (s.empty())
    {
        s.push(item);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, item);
    s.push(temp);
}

// Reverse Stack Recursively
void reverseStackRecursive(stack<int> &s)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        reverseStackRecursive(s);
        insertAtBottom(s, temp);
    }
}

// Reverse Stack without Recursively
void reverseStack(stack<int> &original, stack<int> &reversed)
{
    while (!original.empty())
    {
        reversed.push(original.top());
        original.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack: ";
    stack<int> originalCopy = s; // Create a copy to print the original stack later
    while (!originalCopy.empty())
    {
        cout << originalCopy.top() << " ";
        originalCopy.pop();
    }

    reverseStackRecursive(s);

    // Create a separate stack to store the reversed elements
    stack<int> reversedStack = s;

    cout << "\nReversed Stack Recursively: ";
    while (!reversedStack.empty())
    {
        cout << reversedStack.top() << " ";
        reversedStack.pop();
    }

    stack<int> rev;
    reverseStack(s, rev);
    cout << "\nReversed Stack Iteratively: ";
    while (!rev.empty())
    {
        cout << rev.top() << " ";
        rev.pop();
    }

    return 0;
}
