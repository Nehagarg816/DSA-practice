#include <iostream>
using namespace std; // Circular Queue
class CircularQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;
    CircularQueue(int N)
    {
        size = N;
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
    int *Enqueue(int d)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        { // to check Queue is full or not
            cout << "Queue is Full" << endl;
        }
        else if (front == -1)
        { // first element to push
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain circular nature
        }
        else
        {
            rear++;
        }
        arr[rear] = d;
        return arr;
    }
    int Dequeue()
    {
        if (front == -1) // to check Queue is empty or not
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int s = arr[front];
        arr[front] = -1;
        if (front == rear) // to check only one element is present
        {
            front = rear = -1;
        }
        else if (front == size - 1) // to maintain circular nature
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return s;
    }
};
int main()
{
    CircularQueue c(5);
    c.Dequeue();
    c.Enqueue(1);
    c.Enqueue(2);
    c.Enqueue(3);
    c.Enqueue(4);
    c.Enqueue(5);
    c.print();
    c.Enqueue(6);
    return 0;
}