#include <iostream>
using namespace std; // print digits of a number using recursion
void digit(int n, string str[])
{
    if (n == 0)
    {
        return;
    }
    int num;
    num = n % 10;
    n = n / 10;
    digit(n, str);
    cout << str[num] << " ";
}
int main()
{
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin >> n;
    digit(n, s);
    return 0;
}