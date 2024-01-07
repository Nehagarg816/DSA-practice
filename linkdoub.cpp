#include <iostream>
using namespace std; // Doubly Linked List
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Node with value " << value << " is deleted" << endl;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp->prev = temp;
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    int i = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void InsertionAtHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void InsertionAttail(Node *&tail, Node *&head, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head->next = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void InsetionAtPosition(Node *&head, Node *&tail, int d, int pos)
{
    Node *temp = new Node(d);
    Node *t = head;
    for (int i = 0; i < pos - 1; i++)
    {
        t = t->next;
    }
    temp->next = t->next;
    temp->prev = t;
    t->next = temp;
}
void DeletionAtHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
}
void DeletionAtPosition(Node *&head, Node *&tail, int pos)
{
    Node *curr = head;
    Node *past = NULL;
    int i = 1;
    while (i < pos)
    {
        past = curr;
        curr = curr->next;
        i++;
    }
    curr->prev = NULL;
    past->next = curr->next;
    curr->next = NULL;
    delete curr;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertionAtHead(head, tail, 1);
    InsertionAtHead(head, tail, 2);
    InsertionAtHead(head, tail, 3);
    print(head);
    DeletionAtHead(head, tail);
    print(head);
    DeletionAtHead(head, tail);
    print(head);
    InsertionAttail(tail, head, 2);
    InsertionAttail(tail, head, 4);
    print(head);
    InsetionAtPosition(head, tail, 3, 2);
    print(head);
    cout << getLength(head) << endl;
    DeletionAtHead(head, tail);
    print(head);
    DeletionAtPosition(head, tail, 2);
    print(head);
    return 0;
}