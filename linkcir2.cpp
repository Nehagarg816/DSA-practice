#include <iostream>
using namespace std; // Insertion and reverse in circular linked list
class Node
{
public:
    int data;
    Node *next;
    void display(Node *head)
    {
        Node *ptr = head;
        cout << ptr->data << " ";
        ptr = ptr->next;
        while (ptr != head)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    int InsertionAtFront(Node *head, int data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        Node *p = head;
        p = p->next;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        head = ptr;
        display(head);
        cout << endl;
    }
    void reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        do
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);
        head->next = prev;
        display(head);
    }
};

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = head;
    head->InsertionAtFront(head, 5);
    head->reverse(head);
    return 0;
}