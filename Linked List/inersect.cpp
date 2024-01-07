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
void insertNode(Node *&head, int d)
{
    Node *temp = new Node(d);
    Node *curr = head;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}
void print(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
Node *intersect(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *head3 = NULL;
    Node *curr3 = head3;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data == curr2->data)
        {
            Node *temp = new Node(curr1->data);
            if (head3 == NULL)
            {
                head3 = temp;
                curr3 = head3;
            }
            else
            {
                curr3->next = temp;
                curr3 = curr3->next;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if (curr1->data < curr2->data)
        {
            curr1 = curr1->next;
        }
        else
        {
            curr2 = curr2->next;
        }
    }
    return head3;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    insertNode(head1, 1);
    insertNode(head1, 2);
    insertNode(head1, 3);
    insertNode(head1, 4);
    insertNode(head1, 6);
    insertNode(head2, 2);
    insertNode(head2, 4);
    insertNode(head2, 6);
    insertNode(head2, 8);
    print(head1);
    print(head2);
    Node *head3 = intersect(head1, head2);
    print(head3);
    return 0;
}