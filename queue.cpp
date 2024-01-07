#include <iostream>
#include <queue>
using namespace std; // queue is a container which follows FIFO principle
void print(queue<int> qu)
{
    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    q.push(10); // push element in queue
    q.push(20);
    q.push(30);
    cout << q.size() << endl;  // size of queue
    cout << q.front() << endl; // front element of queue
    cout << q.back() << endl;  // back element of queue
    print(q);
    if (q.empty()) // check queue is empty or not
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    q.pop(); // pop element from queue
    print(q);
    cout << (-1) % 1 << endl; // check queue is empty
    return 0;
}