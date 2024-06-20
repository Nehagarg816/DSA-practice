#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr, int n) // TC - O(N*N), easy, stable algorithm, useful for small data and nearly sorted data,not much efficient
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    vector<int> arr = {6, 8, 2, 5, 1};
    int n = arr.size();
    insertionSort(arr, n);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}