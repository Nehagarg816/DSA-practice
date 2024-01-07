#include <iostream>
using namespace std;
// Insertion of an element in an array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int index(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return i;
        }
    }
}
int insertionSort(int arr[], int size, int element, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index(arr, 5); i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index(arr, 5)] = element;
    return 1;
}
int main()
{
    int arr[100];
    int element;
    cin >> element;
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    display(arr, 5);
    insertionSort(arr, 5, element, 100);
    size += 1;
    display(arr, size);

    return 0;
}