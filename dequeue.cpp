#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cout << (-1) % 1 << endl;
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(5);
    dq.push_front(6);
    dq.push_front(7);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    dq.pop_back();
    dq.pop_front();
    cout << dq.front() << endl;
    cout << dq.back();
}