#include <iostream>
using namespace std; // Deletion of an element from an array

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int DeletionSort(int arr[], int size, int index)
{
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}
int main()
{
    int arr[100];
    int index;
    cin >> index;
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    display(arr, 5);
    DeletionSort(arr, 5, index);
    size -= 1;
    display(arr, size);
    return 0;
}