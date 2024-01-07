#include <bits/stdc++.h>
// HackerRank problem:- Insert a node at the tail of a linked list
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *&head, int data)
{
    if (head == NULL)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
        head = node;
        head->next = NULL;
        return head;
    }

    SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    print_singly_linked_list(head);
}

int main()
{
    SinglyLinkedListNode *head = new SinglyLinkedListNode(1);
    SinglyLinkedListNode *second = new SinglyLinkedListNode(2);
    print_singly_linked_list(head);
    insertNodeAtTail(head, 3);

    return 0;
}