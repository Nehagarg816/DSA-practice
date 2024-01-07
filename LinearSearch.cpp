#include <iostream>
using namespace std; // Linear Search
bool LinearSearch(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int a[] = {2, 4, 1, 3, 8, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 6;
    cout << LinearSearch(a, key, n) << endl;
    return 0;
}