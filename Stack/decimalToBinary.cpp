#include <bits/stdc++.h>
using namespace std;
void decimalToBinary(int n)
{
    stack<int> s;
    if (n == 0)
    {
        cout << "0";
        return;
    }
    while (n > 0)
    {
        s.push(n % 2);
        n = n / 2;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
int main()
{
    int n = 5;
    decimalToBinary(n);
    return 0;
}