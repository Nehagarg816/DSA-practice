#include <iostream>
using namespace std; // Implementation of doubly linked list

// Creation of Double Linked List
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
// Insertion at the beginning of the Doubly Linked List
void insertAtBeginning(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        cout << d << " is inserted at the beginning" << endl;
        return;
    }
    temp->next = head;
    temp->prev = NULL;
    head = temp;
    cout << d << " is inserted at the beginning" << endl;
}
// Insertion at the end of the Doubly Linked List
void insertAtEnd(Node *&head, int d)
{
    Node *curr = head;
    Node *temp = new Node(d);
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
    temp->prev = curr;
    temp->next = NULL;
    cout << d << " is inserted at the end" << endl;
}
// Insertion at the specified position of the Doubly Linked List
void insertAfterPosition(Node *&head, int pos, int data)
{
    Node *current = head;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }
    Node *temp = new Node(data);
    temp->next = current->next;
    temp->prev = current;
    current->next = temp;
    if (current->next != NULL)
    {
        current->next->prev = temp;
    }
    else
    {
        cout << "The list has only one node." << endl;
    }
}
// Counting the nodes in the doubly Linked List
int lengthOfDLL(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
// Deleting a node from the front of the Doubly Linked List
void deleteFromFront(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node is deleted from the beginning" << endl;
    }
}
// Deleting a node from the back of the Doubly Linked List
void deleteFromEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty!";
        return;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        Node *temp = current;
        current = current->prev;
        delete temp;
        current->next = NULL;
        cout << "Node is deleted from end" << endl;
    }
}
// Delete node from the specified position in doubly Linked List
void deleteAtPosition(Node *&head, int pos)
{
    Node *curr = head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL || curr->next == NULL)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    Node *del = curr->next;
    curr->next = del->next;
    del->next->prev = curr;
    delete del;
    cout << "Deleted at position: " << pos << endl;
}
// Traversal of the List
void print(Node *&head)
{
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
    Node *head = NULL;
    insertAtBeginning(head, 10);
    print(head);
    insertAtBeginning(head, 20);
    print(head);
    insertAtEnd(head, 30);
    print(head);
    insertAtEnd(head, 50);
    print(head);
    insertAfterPosition(head, 2, 40);
    print(head);
    deleteFromFront(head);
    print(head);
    deleteFromEnd(head);
    print(head);
    deleteAtPosition(head, 3);
    print(head);
    cout << "Number of Nodes in the Doubly Linked List is " << lengthOfDLL(head) << endl;
    return 0;
}