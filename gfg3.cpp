//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int firstElementKTime(int a[], int n, int k)
    {
        int s = a[0];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == s)
            {
                count++;
            }
            if (count == k)
            {
                return s;
            }
            else
            {
                return -1;
            }
            count = 0;
            s = a[j + 1];
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.firstElementKTime(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends