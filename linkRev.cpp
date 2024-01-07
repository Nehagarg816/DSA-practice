#include <iostream>
using namespace std; // Reverse a Linked List
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        next = NULL;
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
void InsertNode(Node *&head, int d)
{
    Node *curr = head;
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = temp;
        temp->next = NULL;
    }
}
Node *ReverseLinkedList(Node *head) // Iterative Approach O(n) time and O(1) space
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void Reverse(Node *&head, Node *curr, Node *prev) // Recursive Approach O(n) time and O(n) space
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    else
    {
        Node *forward = curr->next;
        Reverse(head, forward, curr);
        curr->next = prev;
    }
}
Node *ReverseLL(Node *head) // Recursive Approach which returns head node O(n) time and O(n) space
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *newHead = ReverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
}
int main()
{
    Node *head = NULL;
    InsertNode(head, 1);
    InsertNode(head, 2);
    InsertNode(head, 3);
    print(head);
    // Reverse(head, head, NULL);
    // print(head);
    Node *newNode = ReverseLL(head);
    print(newNode);
    // Node *neNode = ReverseLinkedList(head);
    // print(neNode);
    return 0;
}