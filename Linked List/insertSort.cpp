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
Node *InsertSort(Node *head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL || d < head->data)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < d)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
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
    Node *head = new Node(25);
    InsertNode(head, 36);
    InsertNode(head, 47);
    InsertNode(head, 58);
    InsertNode(head, 69);
    InsertNode(head, 80);
    // Node *head = new Node(50);
    // InsertNode(head, 100);
    print(head);
    head = InsertSort(head, 19);
    print(head);
    return 0;
}