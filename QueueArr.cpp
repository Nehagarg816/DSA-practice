#include <iostream>
using namespace std; // Implementation of Queues using Arrays
class Queue
{
public:
    int size;
    int *arr;
    int front;
    int rear;
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void print()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isFull()
    {
        if (front == 0 && rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int *Enqueue(int d)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = d;
        cout << d << " is pushed in the queue" << endl;
        return arr;
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            return arr[front];
        }
    }
    int *Dequeue()
    {
        cout << getFront() << " is popped from the queue" << endl;
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        return arr;
    }
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            return arr[rear];
        }
    }
};

int main()
{
    Queue q(5);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.print();
    q.Enqueue(6);
    q.Dequeue();
    q.print();
    cout << "Front element in the queue is " << q.getFront() << endl;
    cout << "Rear element in the queue is " << q.getRear() << endl;
    return 0;
}