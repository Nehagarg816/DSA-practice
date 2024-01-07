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
    Node *temp = tail->next;
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
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
    }
    cout << endl;
}
// Insertion at the beginning in Circular LL
void InsertionAtBeg(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
    }
    cout << d << " is inserted at the beginning" << endl;
}
// Insertion in Circular LL
void InsertionAtPosition(Node *&tail, int ele, int d)
{
    Node *temp = new Node(d);
    // empty node
    if (tail == NULL)
    {
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
        temp->next = curr->next;
        curr->next = temp;
    }
}
void InsertionAtEnd(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp; // Update the tail to the new node
    }
    cout << d << " is inserted at the end" << endl;
}

// Delete node from the beginning of circular LL
void DeleteFromBeginning(Node *&tail)
{
    if (tail == NULL)
    {
        return;
    }
    Node *temp = tail->next;
    tail->next = temp->next;
    temp->next = NULL; // Set next to NULL before deleting
    delete temp;
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
// Delete node from the end of the Circular LL
void DeleteEnd(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "List is Empty\n";
        return;
    }
    Node *temp = tail;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    tail->next = NULL;
    delete tail;
    tail = temp;
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
void Search(Node *&tail, int key)
{
    Node *temp = tail;
    do
    {
        if (temp->data == key)
        {
            cout << "Element found in the List" << endl;
        }
        temp = temp->next;
    } while (temp != tail);
}
int Count(Node *&tail)
{
    int count = 0;
    Node *temp = tail;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != tail);
    return count;
}
int main()
{
    Node *tail = NULL;
    InsertionAtBeg(tail, 1);
    print(tail);
    InsertionAtEnd(tail, 3);
    print(tail);
    InsertionAtBeg(tail, 2);
    print(tail);
    InsertionAtPosition(tail, 2, 4);
    print(tail);
    InsertionAtPosition(tail, 3, 5);
    print(tail);
    InsertionAtPosition(tail, 5, 7);
    print(tail);
    DeleteFromBeginning(tail);
    print(tail);
    DeletionNode(tail, 2);
    print(tail);
    DeleteEnd(tail);
    print(tail);
    Search(tail, 4);
    cout << "Number of Nodes in the Circular Linked List is " << Count(tail) << endl;
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