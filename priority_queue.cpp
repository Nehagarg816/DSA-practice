#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int priority;
    Node *next;

    Node(int value, int prio)
    {
        data = value;
        priority = prio;
        next = nullptr;
    }
};

class PriorityQueue
{
private:
    Node *front;

public:
    PriorityQueue()
    {
        front = nullptr;
    }

    ~PriorityQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int value, int priority)
    {
        Node *newNode = new Node(value, priority);

        if (isEmpty() || priority > front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *temp = front;

            while (temp->next != nullptr && temp->next->priority >= priority)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << value << " with priority " << priority << " enqueued to the priority queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        cout << temp->data << " with priority " << temp->priority << " dequeued from the priority queue." << endl;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty. Cannot peek." << endl;
            return -1;
        }

        return front->data;
    }
};

int main()
{
    PriorityQueue myPriorityQueue;
    myPriorityQueue.enqueue(1, 3);
    myPriorityQueue.enqueue(2, 1);
    myPriorityQueue.enqueue(3, 2);
    cout << "Front element: " << myPriorityQueue.peek() << endl;
    myPriorityQueue.dequeue();
    myPriorityQueue.dequeue();
    myPriorityQueue.dequeue();
    cout << "Is the priority queue empty? " << (myPriorityQueue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
