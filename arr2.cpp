#include <iostream>
using namespace std;

int linearSearch(int arr[], int numb, int key)
{
    for (int i = 0; i < numb; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int n;
    cin >> n;
    cout << linearSearch(arr, num, n);

    return 0;
}