#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n and arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right < n and arr[largest] < arr[right])
    {
        largest = right;
    }
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}
void print(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {-1, 10, 15, 7, 19, 8, 6};
    int n = arr.size();
    // code here
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i, n);
    }
    print(arr);
    return 0;
}