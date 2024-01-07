#include <iostream>
using namespace std; // Remove duplicates from an unsorted linked list
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
Node *UnsortedLink(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        Node *curr = head;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            while (temp != NULL)
            {
                if (temp->data == curr->data)
                {
                    Node *next_next = temp->next;
                    Node *NextNode = temp;
                    delete (NextNode);
                    curr->next = next_next;
                }
                else
                {
                    temp = temp->next;
                }
            }
            curr = curr->next;
        }
        return head;
    }
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(1);
    print(head);
    Node *head2 = UnsortedLink(head);
    print(head2);
    return 0;
}