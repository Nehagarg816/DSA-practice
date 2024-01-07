#include <iostream>
using namespace std; // Traversal of Doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
class Solution
{
public:
    int data;
    struct Node *next;
    struct Node *prev;
    struct Node *display(struct Node *head)
    {
        struct Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
            temp->prev = temp;
        }
        return head;
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
    head->prev = NULL;
    second->data = 8;
    second->next = third;
    second->prev = head;
    third->data = 9;
    third->next = fourth;
    third->prev = second;
    fourth->data = 10;
    fourth->next = NULL;
    fourth->prev = third;
    Solution n;
    n.display(head);
    return 0;
}