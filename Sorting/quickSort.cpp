#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int pivot(vector<int> &arr, int low, int high) // TC - O(N*logN), Worst Case - O(N*N), useful for large data, not stable, low overhead
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int a = pivot(arr, low, high);
        quickSort(arr, low, a - 1);
        quickSort(arr, a + 1, high);
    }
}
int main()
{
    vector<int> arr = {3, 7, 5, 1, 9};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}