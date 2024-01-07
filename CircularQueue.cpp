#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int front, rear, size;
    int *array;

public:
    CircularQueue(int capacity)
    {
        size = capacity;
        array = new int[size];
        front = rear = -1;
    }

    ~CircularQueue()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        array[rear] = value;
        cout << value << " enqueued to the circular queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int removedValue = array[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        cout << removedValue << " dequeued from the circular queue." << endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Assuming -1 is used as an error value; you can modify it based on your requirements
        }

        return array[front];
    }
};

int main()
{
    CircularQueue myCircularQueue(3);

    myCircularQueue.enqueue(1);
    myCircularQueue.enqueue(2);
    myCircularQueue.enqueue(3);

    cout << "Front element: " << myCircularQueue.peek() << endl;

    myCircularQueue.dequeue();
    myCircularQueue.dequeue();
    myCircularQueue.dequeue();
    cout << "Is the circular queue empty? " << (myCircularQueue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
