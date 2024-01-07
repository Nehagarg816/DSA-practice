//{ Driver Code Starts
// Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream> //Reverse a linked list
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to reverse a linked list.
    struct Node *reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

//{ Driver Code Starts.

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int n, l, t, fistdata;
    while (t--)
    {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        cin >> fistdata;
        head = new Node(fistdata);
        tail = head;
        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution ob;
        ob.reverseList(head);
        printList(head);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends