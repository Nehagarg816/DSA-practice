#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int exp;
    Node *next;
    Node(int d, int e)
    {
        this->data = d;
        this->exp = e;
        this->next = NULL;
    }
};
void InsertNode(Node *&head, int d, int e)
{
    Node *temp = new Node(d, e);
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
Node *Polynomial(Node *temp1, Node *temp2)
{
    Node *temp3 = new Node(0, 0);
    Node *result = temp3;
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1->exp > temp2->exp)
        {
            Node *temp = new Node(temp1->data, temp1->exp);
            temp3->next = temp;
            temp1 = temp1->next;
        }
        else if (temp1->exp < temp2->exp)
        {
            Node *temp = new Node(temp2->data, temp2->exp);
            temp3->next = temp;
            temp2 = temp2->next;
        }
        else
        {
            Node *temp = new Node(temp1->data + temp2->data, temp1->exp);
            temp3->next = temp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
    }
    return result->next;
}
void print(Node *&head)
{
    cout << "Traversal of Linked List" << endl;
    Node *curr = head;
    while (curr != NULL)
    {
        cout << "(" << curr->data << "," << curr->exp << ") ->";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    InsertNode(temp1, 10, 6);
    InsertNode(temp1, 13, 2);
    InsertNode(temp1, 1, 0);
    InsertNode(temp2, 16, 14);
    InsertNode(temp2, 13, 2);
    InsertNode(temp2, 14, 1);
    print(temp1);
    print(temp2);
    Node *temp3 = Polynomial(temp1, temp2);
    print(temp3);
    return 0;
}