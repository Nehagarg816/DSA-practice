#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
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
Node *ReverseAlternate(Node *&head)
{
    Node *temp = head->next;
    Node *prev = head;
    Node *rev = temp;
    while (temp != NULL)
    {
        if (temp != NULL && temp->next != NULL)
        {
            prev->next = temp->next;
            temp = temp->next->next;
            rev->next = temp;
            prev = prev->next;
            rev->next = temp;
        }
    }
    Node *pre = NULL;
    Node *curr = rev;
    Node *nextNode = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextNode;
    }
    Node *current = prev;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = pre;
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
    Node *head = new Node(10);
    InsertNode(head, 4);
    InsertNode(head, 9);
    InsertNode(head, 1);
    InsertNode(head, 3);
    InsertNode(head, 5);
    InsertNode(head, 9);
    InsertNode(head, 4);
    print(head);
    head = ReverseAlternate(head);
    print(head);
    // cout << 3 + 5;
    return 0;
}