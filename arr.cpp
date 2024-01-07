#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    int maxNo = INT_MIN; // Initial max number with minimum number so that it can attain maximum number present in array
    int minNo = INT_MAX; // Initial min number with maximum number so that it can attain minimum number present in array
    for (int i = 0; i < 10; i++)
    {
        maxNo = max(maxNo, arr[i]);
        minNo = min(minNo, arr[i]);
    }
    cout << maxNo << " " << minNo;
    return 0;
}