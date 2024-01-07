#include <iostream>
using namespace std; // remove duplicates from a sorted linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertNode(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
Node *RemoveDuplicateSorted(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *next_node = curr->next;
            delete (next_node);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node(1);
    InsertNode(head, 2);
    InsertNode(head, 2);
    InsertNode(head, 2);
    InsertNode(head, 3);
    printList(head);
    Node *head2 = RemoveDuplicateSorted(head);
    printList(head2);
    return 0;
}