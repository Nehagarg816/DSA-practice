#include <iostream>
using namespace std; // Deletion of a node from the end of the linked list

class Node
{
public:
    int data;
    Node *next;
    void DeletionLast(Node *head)
    {
        Node *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        Node *q = ptr->next;
        ptr->next = NULL;
        free(q);
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    head->data = 7;
    head->next = second;
    second->data = 8;
    second->next = third;
    third->data = 9;
    third->next = fourth;
    fourth->data = 10;
    fourth->next = NULL;
    class Node n;
    n.DeletionLast(head);
    return 0;
}