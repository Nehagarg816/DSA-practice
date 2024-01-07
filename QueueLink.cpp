#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class QueueLink
{
public:
    int size;
    Node *front;
    Node *rear;
    QueueLink(int n)
    {
        size = n;
        front = NULL;
        rear = NULL;
    }
    void enQueue(int d)
    {
        Node *temp = new Node(d);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            front->next = NULL;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            temp->next = NULL;
        }
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
};
int main()
{
    Node *head = new Node(1);
    QueueLink q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.print(head);
    return 0;
}