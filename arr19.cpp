#include <iostream>
using namespace std; // Find the number that occurs k times in an array

int findNumber(int arr[], int n, int k)
{
    int s = arr[0];
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == s)
        {
            count++;
        }
        if (count == k)
        {
            return s;
        }
        else
        {
            return -1;
        }
        count = 0;
        s = arr[j + 1];
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << findNumber(arr, n, k);
    return 0;
}