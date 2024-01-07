//{ Driver Code Starts
#include <bits/stdc++.h> //gfg problem:Subarray with given sum
using namespace std;

// } Driver Code Ends
// Function to find subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int arr[], int n, int s) // test case 163/165
{

    // Your code here
    int i = 0, j = 0;
    int sum = 0;
    vector<int> v;
    while (j < n && sum + arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }
    if (sum == s)
    {
        v.push_back(i + 1);
        v.push_back(j);
        return v;
    }
    while (j < n)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == s)
        {
            v.push_back(i + 1);
            v.push_back(j + 1);
            return v;
        }
        j++;
    }
    v.push_back(-1);
    return v;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> res = subarraySum(a, n, s);
        for (i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends