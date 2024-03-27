#include <iostream>
using namespace std;
void countSort(int arr[])
{
    int k = arr[0];
    for (int i = 0; i < 6; i++)
    {
        k = max(k, arr[i]);
    }
    int count[10] = {0};
    for (int i = 0; i < 6; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    int output[6];
    for (int i = 5; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < 6; i++)
    {
        arr[i] = output[i];
    }
}
int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    countSort(arr);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}