#include <iostream>
using namespace std; // Insertion of a node in a sorted doubly linked list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertNode(Node *&head, int d)
{
    Node *temp = new Node(d);
    Node *curr = head;
    Node *prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    temp->prev = curr;
    temp->next = curr->next;
    curr->next = temp;
}
Node *InsertAtDoubleList(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL && curr->data < temp->data)
    {
        prev = curr;
        curr = curr->next;
    }
    temp->prev = prev;
    temp->next = curr;
    if (prev != NULL)
    {
        prev->next = temp;
    }
    else
    {
        head = temp;
    }
    if (curr != NULL)
    {
        curr->prev = temp;
    }
    return head;
}
int main()
{
    Node *head = new Node(10);
    InsertNode(head, 20);
    InsertNode(head, 60);
    printList(head);
    InsertAtDoubleList(head, 30);
    InsertAtDoubleList(head, 40);
    InsertAtDoubleList(head, 50);
    printList(head);
    return 0;
}