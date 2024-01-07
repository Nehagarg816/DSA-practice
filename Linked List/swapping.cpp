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
int length(Node *head)
{
    int count = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
Node *swapping(Node *head, int k)
{
    int n = length(head);
    if (k < 1 || k > n)
    {
        cout << "Invalid value of k" << endl;
        return head;
    }
    if (k == 1)
    {
        Node *firstNode = head;
        Node *secondNode = head;
        for (int i = 0; i < n - 1; i++)
        {
            secondNode = secondNode->next;
        }
        Node *temp = firstNode->next;
        firstNode->next = secondNode->next;
        secondNode->next = temp;
        head = secondNode;
        return head;
    }
    Node *curr = head;
    Node *prev1 = NULL;
    Node *prev2 = NULL;
    for (int i = 1; i < k; i++)
    {
        prev1 = curr;
        curr = curr->next;
    }
    Node *temp = curr->next;
    for (int i = 1; i < n - k; i++)
    {
        prev2 = temp;
        temp = temp->next;
    }
    Node *nextNode = temp->next;
    temp->next = curr->next;
    curr->next = nextNode;
    prev2->next = curr;
    prev1->next = temp;
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
    print(head);
    int k = 2;
    Node *ans = swapping(head, k);
    print(ans);
    return 0;
}