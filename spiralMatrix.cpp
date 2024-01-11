#include <iostream>
#include <vector>
using namespace std; // Spiral Order Printing of matrix
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row * col;
    int stRow = 0;
    int stCol = 0;
    int endRow = row - 1;
    int endCol = col - 1;
    while (count < total)
    {
        // print starting row
        for (int index = stCol; index <= endCol and count < total; index++)
        {
            ans.push_back(matrix[stRow][index]);
            count++;
        }
        stRow++;
        // print ending column
        for (int index = stRow; index <= endRow and count < total; index++)
        {
            ans.push_back(matrix[index][endCol]);
            count++;
        }
        endCol--;
        // printing ending row
        for (int index = endCol; index >= stCol and count < total; index--)
        {
            ans.push_back(matrix[endRow][index]);
            count++;
        }
        endRow--;
        // printing starting col
        for (int index = endRow; index >= stRow and count < total; index--)
        {
            ans.push_back(matrix[index][stCol]);
            count++;
        }
        stCol++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix;
    matrix.push_back({1, 2, 3});
    matrix.push_back({4, 5, 6});
    matrix.push_back({7, 8, 9});
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}