#include <iostream>
using namespace std; // Matrix multiplication in 2D array format

int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr1[i][j];
        }
    }
    int arr2[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr2[i][j];
        }
    }
    int ans = 0;
    int arr3[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                ans += arr1[i][k] * arr2[k][j];
            }
            arr3[i][j] = ans;
            cout << arr3[i][j] << " ";
            ans = 0;
        }
        cout << endl;
    }

    return 0;
}