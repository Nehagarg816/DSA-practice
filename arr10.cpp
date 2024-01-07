#include <iostream>
using namespace std;

void SubArray(int arr[], int n)
{
    int sub = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sub = +arr[j];
            cout << sub << " ";
        }
    }
}

int main()
{
    int arr[10];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    SubArray(arr, 5);
    return 0;
}