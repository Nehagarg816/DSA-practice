#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    head->data = 7;
    head->next = second;
    second->data = 8;
    second->next = third;
    third->data = 9;
    third->next = NULL;

    cout << head->data << " ";
    cout << second->data << " ";
    cout << third->data << " ";
    cout << head->next->data << " ";
    return 0;
}