#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int i)
{
    int n = arr.size();
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n and arr[left] >= arr[largest])
    {
        largest = left;
    }
    if (right < n and arr[right] >= arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest);
    }
}
int main()
{
    vector<int> arr = {-1, 10, 15, 7, 19, 8, 6};
    int n = arr.size();
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i);
    }
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << (is_heap(arr.begin() + 1, arr.end()) ? "Yes" : "No");
    return 0;
}