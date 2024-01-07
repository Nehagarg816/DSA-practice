#include <iostream>
using namespace std; // Book Allocation Problem

int isPossible(int arr[], int n, int m, int mid)
{
    int pageCount = 0;
    int StudentCount = 1;
    for (int i = 0; i < n; i++)
    {
        if (pageCount + arr[i] <= mid)
        {
            pageCount += arr[i];
        }
        else
        {
            StudentCount++;
            if (StudentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageCount = arr[i];
        }
    }
    return true;
}
int main()
{
    int m, n;
    cin >> m >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(a, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    cout << ans << endl;

    return 0;
}