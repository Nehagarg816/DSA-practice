#include <iostream>
using namespace std;

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
    cout << "Traversal of Linked List" << endl;
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void Ins_beg(Node *&head, int d)
{
    Node *temp = new Node(d);
    Node *curr = head;
    if (head == NULL)
    {
        head = temp;
    }
    temp->next = head;
    head = temp;
    cout << "Node with " << d << " data has been inserted in linked list" << endl;
    print(head);
}
void Ins_end(Node *&head, int d)
{
    Node *temp = new Node(d);
    Node *curr = head;
    if (head == NULL)
    {
        head = temp;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    cout << "Node with " << d << " data has been inserted in linked list" << endl;
    print(head);
}
void Ins_btw(Node *&head, int d, int key)
{
    Node *temp = new Node(d);
    Node *curr = head;
    if (head == NULL)
    {
        head = temp;
    }
    while (curr->data != key)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    cout << "Node with " << d << " data has been inserted in linked list" << endl;
    print(head);
}
void Insertion(Node *&head, int d)
{
    int choice;
    cout << "Enter 1 for Insertion at the beginning" << endl;
    cout << "Enter 2 for Insertion at the end" << endl;
    cout << "Enter 3 for Insertion in between the linked list" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Ins_beg(head, d);
        break;

    case 2:
        Ins_end(head, d);
        break;

    case 3:
        int key;
        cout << "Enter Node value after which you want to insert a Node" << endl;
        cin >> key;
        Ins_btw(head, d, key);
        break;

    default:
        break;
    }
}
void Deletion(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    int choice;
    cout << "Enter 1 for Deleting a node from the beginning of a Linked List" << endl;
    cout << "Enter 2 for Deleting a node from the end of a Linked List" << endl;
    cout << "Enter 3 for Deleting a node in between of a Linked List" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    Node *curr = head;
    switch (choice)
    {
    case 1:
        head = curr->next;
        curr->next = NULL;
        cout << "Node has been deleted" << endl;
        break;

    case 2:
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = NULL;
        cout << "Node has been deleted" << endl;
        break;

    case 3:
        int ele;
        cout << "Enter a Node value which you want to delete" << endl;
        cin >> ele;
        while (curr->next->data != ele)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        curr->next->next = NULL;
        cout << "Node has been deleted" << endl;
        break;

    default:
        break;
    }
    print(head);
}

bool Searching(Node *&head)
{
    int ele;
    cout << "Enter element you want to search in linked list: ";
    cin >> ele;
    if (head == NULL)
    {
        return false;
    }
    Node *curr = head;
    while (curr->data != ele)
    {
        curr = curr->next;
    }
    if (curr != NULL)
    {
        cout << "Given element is present in linked list" << endl;
        return true;
    }
    else
    {
        cout << "Given element is not present in linked list" << endl;
        return false;
    }
}
int main()
{
    Node *head = new Node(10);
    int operation;
    cout << "Enter 1 for Insertion in a Singly Linked List" << endl;
    cout << "Enter 2 for Deletion in a Singly Linked List" << endl;
    cout << "Enter 3 for Searching in a Singly Linked List" << endl;
    cout << "Enter 4 for Printing a Singly Linked List" << endl;
    cin >> operation;
    switch (operation)
    {
    case 1:
        int d;
        cin >> d;
        Insertion(head, d);
        break;
    case 2:
        Deletion(head);
        break;
    case 3:
        Searching(head);
        break;
    case 4:
        print(head);
        break;
    default:
        break;
    }
    return 0;
}