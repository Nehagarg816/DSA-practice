#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};
void InsertNode(Node *&head, int d)
{
    Node *temp = new Node(d);
    Node *curr = head;
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
}
Node *swapNode(Node *head, int n)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    forward = curr->next;
    prev->next = forward;
    curr->next = forward->next;
    forward->next = curr;
    return head;
}
void print(Node *&head)
{
    cout << "Traversal of Linked List" << endl;
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(1);
    InsertNode(head, 2);
    InsertNode(head, 3);
    InsertNode(head, 4);
    print(head);
    int n = 2;
    head = swapNode(head, n);
    print(head);
    return 0;
}