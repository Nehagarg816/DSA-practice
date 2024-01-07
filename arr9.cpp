#include <iostream>
using namespace std; // Finding maximum number of array

int MaxNumber(int arr[], int n) // 1st method
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int MaxNumber2(int arr[], int num) // 2nd method
{
    int m = arr[0];
    ;
    for (int i = 0; i < num; i++)
    {
        m = max(m, arr[i]);
    }
    return m;
}
int main()
{
    int arr[10];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cout << MaxNumber(arr, 5) << endl;
    cout << MaxNumber2(arr, 5);

    return 0;
}