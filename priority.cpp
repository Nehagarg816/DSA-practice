#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int pri;
    Node *next;
    Node *front;
    Node *rear;
    Node(int d, int p)
    {
        this->data = d;
        this->pri = p;
        this->next = NULL;
        this->front = NULL;
        this->rear = NULL;
    }
};
void InsertNode(Node *&head, int d, int e)
{
    Node *temp = new Node(d, e);
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
Node *prior(Node *head, int d, int p)
{
    Node *temp = new Node(d, p);
    Node *curr = head;
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    Node *prev = NULL;
    while (curr->pri <= p && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        prev->next = temp;
        prev = temp;
    }
    else if (curr == head)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->next = prev->next;
        prev->next = temp;
    }
    return head;
}
void print(Node *&head)
{
    cout << "Traversal of Linked List" << endl;
    Node *curr = head;
    while (curr != NULL)
    {
        cout << "(" << curr->data << "," << curr->pri << ") ->";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    InsertNode(head, 10, 1);
    InsertNode(head, 13, 2);
    InsertNode(head, 1, 5);
    InsertNode(head, 16, 3);
    InsertNode(head, 14, 6);
    print(head);
    cout << "\n\nAfter Prior insertion:\n";
    prior(head, 15, 4);
    print(head);
    return 0;
}