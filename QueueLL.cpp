#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
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

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << value << " enqueued to the queue." << std::endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        std::cout << temp->data << " dequeued from the queue." << std::endl;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr; // If the queue becomes empty, update the rear pointer as well
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot peek." << std::endl;
            return -1; // Assuming -1 is used as an error value; you can modify it based on your requirements
        }
        return front->data;
    }
};

int main()
{
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    std::cout << "Front element: " << myQueue.peek() << std::endl;
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
