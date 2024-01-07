#include <iostream>
#include <map>
using namespace std; // Detect loop in a linked list
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
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void InsertNode(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = NULL;
    }
}
bool DetectLoop(Node *head) // Detect loop in a linked list
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
Node *FloydCycle(Node *head) // Floyd's Cycle Detection Algorithm
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL & fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Loop is present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node *BeginningOfLoop(Node *head) // Find the beginning of the loop
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *slow = head;
        Node *beg = FloydCycle(head);
        if (beg == NULL)
        {
            return NULL;
        }
        while (slow != beg)
        {
            slow = slow->next;
            beg = beg->next;
        }
        return slow;
    }
}
int LoopLength(Node *head) // Find the length of the loop
{
    Node *start = BeginningOfLoop(head);
    if (start == NULL)
    {
        return 0;
    }
    Node *temp = start;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != start);
    return count;
}
Node *RemoveLoop(Node *&head) // Remove the loop
{
    if (head == NULL)
    {
        return head;
    }
    Node *remove = BeginningOfLoop(head);
    Node *temp = remove;
    if (remove == NULL)
    {
        return head;
    }
    while (temp->next != remove)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
int main()
{
    Node *head = NULL;
    InsertNode(head, 1);
    InsertNode(head, 2);
    InsertNode(head, 3);
    InsertNode(head, 4);
    InsertNode(head, 5);
    head->next->next->next = head->next; // Cyclic LL
    // printList(head);
    cout << DetectLoop(head) << endl;
    if (DetectLoop(head) == 1)
    {
        cout << "Loop Detected" << endl;
    }
    else
    {
        cout << "No Loop Detected" << endl;
    }
    Node *loop = BeginningOfLoop(head);
    cout << "Loop starts at " << loop->data << endl;
    RemoveLoop(head);
    printList(head);
    cout << LoopLength(head) << endl;
    return 0;
}