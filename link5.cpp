#include <iostream>
using namespace std; // Deletion of a node from the middle of the linked list

class Node
{
public:
    int data;
    Node *next;
    void DeletionInBetween(Node *head, int index)
    {
        Node *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        Node *q = ptr->next;
        ptr->next = q->next;
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
    n.DeletionInBetween(head, 0);
    return 0;
}