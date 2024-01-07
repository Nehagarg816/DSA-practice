#include <iostream>
using namespace std; // Input Restricted Queue (Dequeue)

class QueueInput
{
public:
    int size;
    int *arr;
    int front;
    int rear;
    QueueInput(int n) // Constructor to initialize the Queue
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void print() // To print the Queue
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int *push_back(int d) // To push elements in the back of the Queue
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue Overflow" << endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = d;
        return arr;
    }
    int *push_front(int data) // To push elements in the front of the Queue
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue Overflow" << endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front--;
        }
        return arr;
    }
    bool isFull() // Acc to push_back to check whether Queue is full or not
    {
        if ((front == 0 && rear == size - 1) || (rear = (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty() // Acc to push_back to check whether Queue is empty or not
    {
        if (front = -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getFront() // Acc to push_back to get front element of Queue
    {
        if (front == -1)
        {
            return -1;
        }

        return arr[front];
    }
    int getRear() // Acc to push_back to get rear element of Queue
    {
        if (rear == -1)
        {
            return -1;
        }

        return arr[rear];
    }
    int *popFront() // To pop elements from the front of the Queue
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        int s = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = 0;
        }
        else if (front = size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
};

int main()
{
    QueueInput i(4);
    i.push_back(1);
    i.push_back(2);
    i.push_back(3);
    i.push_back(4);
    if (i.isFull() == 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        cout << "Queue is not Full" << endl;
    }
    i.print();
    i.push_back(7);
    cout << i.getFront() << endl;
    cout << i.getRear() << endl;
    return 0;
}