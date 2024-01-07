#include <iostream>
using namespace std; // Reverse a linked list in groups of k nodes
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
Node *ReverseK(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *nex = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        count++;
    }
    if (nex != NULL)
    {
        head->next = ReverseK(nex, k);
    }
    return prev;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    print(head);
    Node *newNode = ReverseK(head, 2);
    print(newNode);
    return 0;
}