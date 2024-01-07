#include <iostream>
using namespace std; // Circular Linked Lists
class Node
{
public:
    int data;
    Node *next;
    Node(int x);
    ~Node();
};

Node::Node(int x)
{
    this->data = x;
    this->next = NULL;
}

Node::~Node()
{
    int value = this->data;
    if (this->next != NULL)
    {
        delete next;
        this->next = NULL;
    }
    cout << "Node with value " << value << " is deleted" << endl;
}
// print Circular LL
void print(Node *tail)
{
    Node *temp = tail;
    // empty node
    if (tail == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    // non-empty node
    else
    {
        do
        {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != temp);
    }
    cout << endl;
}
// Insertion in Circular LL
void InsertionAtPosition(Node *&tail, int ele, int d)
{
    // empty node
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        temp->next = temp;
        tail = temp;
    }
    // non-empty node
    else
    {
        Node *curr = tail;
        while (curr->data != ele)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
// Delete node from Circular LL
void DeletionNode(Node *&tail, int ele)
{
    // empty Node
    if (tail == NULL)
    {
        cout << "Nothing to be deleted";
    }
    else
    {
        Node *curr = tail;
        Node *prev = tail;
        while (curr->data != ele)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == tail)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
// Check if it is Circular LL or not
bool isCircular(Node *tail)
{
    if (tail == NULL)
    {
        return true;
    }
    Node *temp = tail->next;
    while (temp != NULL && temp != tail)
    {
        temp = temp->next;
    }
    if (temp == tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Node *tail = NULL;
    InsertionAtPosition(tail, 2, 3);
    InsertionAtPosition(tail, 3, 5);
    print(tail);
    InsertionAtPosition(tail, 5, 7);
    print(tail);
    if (isCircular(tail))
    {
        cout << "Circular Linked List" << endl;
    }
    else
    {
        cout << "Not a Circular Linked List" << endl;
    }
    return 0;
}