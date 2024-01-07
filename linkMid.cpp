#include <iostream>
using namespace std; // Find the middle element of a linked list
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
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Node with value " << value << " is deleted" << endl;
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
int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
int getMid(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }
    else if (head->next->next == NULL)
    {
        return head->next->data;
    }
    else
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (getLength(head) % 2 != 0)
        {
            return slow->data;
        }
        else
        {
            cout << slow->data << " ";
            return slow->next->data;
        }
    }
}
int main()
{
    Node *head = new Node(10);
    InsertNode(head, 20);
    InsertNode(head, 30);
    InsertNode(head, 40);
    InsertNode(head, 50);
    print(head);
    cout << getMid(head) << endl;
    print(head);
    return 0;
}
