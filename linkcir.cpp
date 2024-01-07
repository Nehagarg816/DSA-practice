#include <iostream>
using namespace std; // Circular Linked List
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
    head->display(head);
    return 0;
}