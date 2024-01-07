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
Node *Pair_swap(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head->next;
    Node *temp = head;
    head = curr;
    while (curr != NULL)
    {
        Node *prev = curr->next;
        curr->next = temp;
        if (prev == NULL || prev->next == NULL)
        {
            temp->next = prev;
            break;
        }
        temp->next = prev->next;
        temp = prev;
        curr = prev->next;
    }
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
    Node *head = new Node(1);
    InsertNode(head, 2);
    InsertNode(head, 2);
    InsertNode(head, 4);
    InsertNode(head, 5);
    InsertNode(head, 6);
    InsertNode(head, 7);
    InsertNode(head, 8);
    print(head);
    head = Pair_swap(head);
    print(head);
    return 0;
}