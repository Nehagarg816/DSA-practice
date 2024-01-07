#include <iostream>
#include <vector>
using namespace std; // Selection Sorting of an array using vector STL

void SelectionVector(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    vector<int>::iterator itr;
    for (itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << *itr << " ";
    }
}
// Selection Sorting of an array using vector STL
int main()
{
    int n;
    cin >> n;
    vector<int> arr[n];
    for (int i = 0; i < n; i++)
    {
        int ele = 0;
        cin >> ele;
        arr[i].push_back(ele);
    }
    SelectionVector(*arr, n);
    return 0;
}