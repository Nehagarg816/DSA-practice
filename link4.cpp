#include <iostream>
using namespace std; // Deletion of a node from the beginning of the linked list

class Node
{
public:
    int data;
    Node *next;
    void Deletion(Node *head)
    {
        Node *ptr = new Node;
        ptr = head;
        head = head->next;
        free(ptr);
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
    head->data = 7;
    head->next = second;
    second->data = 8;
    second->next = third;
    third->data = 9;
    third->next = NULL;
    class Node n;
    n.Deletion(head);
    return 0;
}