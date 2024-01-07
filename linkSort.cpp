#include <iostream>
using namespace std; // Remove duplicates from a sorted linked list
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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *InsertNode(Node *head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    }
}
Node *UniqueSortedList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *NextNode = curr->next;
            delete (NextNode);
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
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    print(head);
    Node *head2 = UniqueSortedList(head);
    print(head2);
    return 0;
}