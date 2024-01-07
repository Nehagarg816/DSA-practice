#include <iostream>
using namespace std; // Doubly linked list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node *head) // Print Doubly-linked list
{
    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *InsertNode(Node *&head, int d) // Insert Node in Doubly-linked list
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    temp->prev = curr;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
bool CheckDoublyLL(Node *&head) // Check Doubly-linked list
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    else
    {
        Node *curr = head->next;
        Node *pre = head;
        while (curr->next != NULL)
        {
            if (pre->next != curr && curr->prev != pre)
            {
                return false;
            }
            pre = curr;
            curr = curr->next;
        }
        return true;
    }
}
Node *ReverseDoublyLL(Node *&head) // Reverse Doubly-linked list
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }
    else
    {
        Node *curr = head;
        Node *pre = NULL;
        while (curr != NULL)
        {
            pre = curr->prev;
            curr->prev = curr->next;
            curr->next = pre;
            curr = curr->prev;
        }
        if (pre != NULL)
        {
            head = pre->prev;
        }

        return head;
    }
}
int main()
{
    Node *head = NULL;
    InsertNode(head, 10);
    InsertNode(head, 20);
    InsertNode(head, 30);
    InsertNode(head, 40);
    cout << CheckDoublyLL(head) << endl;
    print(head);
    Node *rev = ReverseDoublyLL(head);
    print(rev);
    return 0;
}