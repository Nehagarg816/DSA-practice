#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (arr[j] > curr && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
    vector<int>::iterator itr;
    for (itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << *itr << " ";
    }
}
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
    insertionSort(*arr, n);
    return 0;
}