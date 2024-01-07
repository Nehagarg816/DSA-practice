#include <iostream>
using namespace std;
// deleting a nth node from last and inserting the node at the nth position from the beginning of the doubly linked list. You are supposed to do this operation by manipulating the links only without creating any new node or change the data in any node
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
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

Node *changeNode(Node *&head, int n)
{
    if (head == NULL)
    {
        return head;
    }
    int count = 0;
    Node *cur = head;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    Node *curr = head;
    for (int i = 0; i < count - n; i++)
    {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    if (curr->next != NULL)
    {
        curr->next->prev = curr->prev;
    }
    curr->next = NULL;
    curr->prev = NULL;
    Node *temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    temp->next->prev = curr;
    curr->next = temp->next;
    temp->next = curr;
    curr->prev = temp;
    return head;
}
void print(Node *head)
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
    InsertNode(head, 3);
    InsertNode(head, 4);
    print(head);
    Node *ans;
    int num = 2;
    ans = changeNode(head, num);
    print(ans);
    return 0;
}
