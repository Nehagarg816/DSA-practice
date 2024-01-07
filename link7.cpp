#include <iostream>
using namespace std;
class Node
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
void printList(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *InsertAtIndex(Node *&head, int d, int index) // Insertion at a given index in a linked list
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
        return head;
    }
    if (head->next == NULL)
    {
        temp->next = NULL;
        head->next = temp;
        return head;
    }
    Node *curr = head;
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
Node *DeletionAtIndex(Node *&head, int d, int index) // Deletion at a given index in a linked list
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    curr->next->next = NULL;
    return head;
}
int main()
{
    Node *head = NULL;
    InsertAtIndex(head, 10, 0);
    InsertAtIndex(head, 20, 1);
    InsertAtIndex(head, 40, 2);
    printList(head);
    InsertAtIndex(head, 30, 2);
    printList(head);
    DeletionAtIndex(head, 30, 2);
    printList(head);
    return 0;
}