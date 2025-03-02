#include <iostream>
using namespace std; // Spiral Order Matrix Traversal

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
    int row_start = 0, row_end = n - 1, column_start = 0, column_end = n - 1,total=n*m,cnt=0;
    while(cnt<total){
        for (int col = column_start; col <= column_end and cnt<total; col++)
        {
            cout << arr[row_start][col] << " ";
            cnt++;
        }
        row_start++;
        for (int row = row_start; row <= row_end and cnt<total; row++)
        {
            cout << arr[row][column_end] << " ";
            cnt++;
        }
        column_end--;
        for (int col = column_end; col >= column_start and cnt<total; col--)
        {
            cout << arr[row_end][col] << " ";
            cnt++;
        }
        row_end--;
        for (int row = row_end; row >= row_start and cnt<total; row--)
        {
            cout << arr[row][column_start] << " ";
            cnt++;
        }
        column_start++;
    }

    return 0;
}
