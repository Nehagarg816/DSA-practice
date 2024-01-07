#include <iostream>
using namespace std; // Searching an element in a sorted matrix

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ele;
    cin >> ele;
    int r = 0, c = m - 1;
    bool found = false;
    while (r < n && c >= 0)
    {
        if (arr[r][c] == ele)
        {
            found == true;
        }
        if (arr[r][c] > ele)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (found)
    {
        cout << "Yes element exists" << endl;
    }
    else
    {
        cout << "No element exists" << endl;
    }
    return 0;
}