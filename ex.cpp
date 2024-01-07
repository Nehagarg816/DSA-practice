#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) // T.C: B(O(N)), A(O(N^2)) W(O(N^2))  SC:O(1)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

void selectionSort(int arr[], int n) // T.C: BAW(O(N^2))  S.C: O(1)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < minIndex)
            {
                minIndex = arr[j];
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n) // T.C: B(O(N)) AW(O(N^2))   S.C: O(1)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int s, int e, int mid)
{
    int i = s;
    int j = mid + 1;
    int k = s;
    int arr2[20];
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        arr2[k] = arr[j];
        j++;
        k++;
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = arr2[i];
    }
}
void mergeSort(int arr[], int s, int e) // T.C: BAW(O(nlogn))  S.C: O(n)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) // T.C: BAW(O(nlogn))    S.C: O(1)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
int partition(int arr[], int n, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = 0; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int n, int low, int high) // T.C: BA(O(nlogn)) W(O(n^2)) S.C:O(n)
{
    if (low < high)
    {
        int pi = partition(arr, n, low, high);
        quickSort(arr, n, low, pi - 1);
        quickSort(arr, n, pi + 1, high);
    }
}
int main()
{
    int arr[] = {2, 4, 1, 7, 5, 3};
    int n = 6;
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    int s = 0;
    int e = n - 1;
    // mergeSort(arr, s, e);
    // heapSort(arr, n + 1);
    quickSort(arr, n, s, e);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}