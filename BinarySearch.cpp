#include <iostream>
using namespace std; // Binary Search
bool BinarySearch(int arr[], int key)
{
    int s = 0;
    int e = 5;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}
int main()
{
    int a[] = {2, 3, 4, 5, 6, 7};
    int key = 5;
    cout << BinarySearch(a, key) << endl;
    return 0;
}