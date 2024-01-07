#include <iostream>
using namespace std; // Transpose of a 2D array

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    /*  1 3 5
        4 6 8
        5 7 9
        Transpose:
        1 4 5
        3 6 8
        5 8 9*/
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}