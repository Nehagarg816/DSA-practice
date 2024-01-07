#include <iostream>
using namespace std; // Insertion at middle in circular linked list
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
    int InsertionAtMiddle(Node *head, int data, int index)
    {
        Node *ptr = new Node;
        ptr->data = data;
        Node *prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        ptr->next = prev->next;
        prev->next = ptr;
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
    head->InsertionAtMiddle(head, 5, 2);
    return 0;
}