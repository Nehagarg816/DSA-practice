#include <iostream>
using namespace std;

int maximumSubArray(int arr[], int n)
{
    int maxSum = arr[0];
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {1, 0, -1, -2, 4};
    int ans = maximumSubArray(arr, 5);
    cout << ans << endl;
    return 0;
}