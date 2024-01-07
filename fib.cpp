#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n == 1 or n == 2)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        int term = fibonacci(i);
        cout << term << " ";
    }
    return 0;
}