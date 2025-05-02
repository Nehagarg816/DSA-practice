#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l, ans = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            ans += n1 - i;
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
    return ans;
}

int countInversions(vector<int> &arr, int l, int r)
{
    int ans = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        ans += countInversions(arr, l, mid);
        ans += countInversions(arr, mid + 1, r);
        ans += merge(arr, l, mid, r);
    }
    return ans;
}

int InversionCount(vector<int> &arr)
{
    int n = arr.size();
    return countInversions(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};

    cout << InversionCount(arr);
    return 0;
}

