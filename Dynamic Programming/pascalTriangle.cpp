#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    if (numRows == 0)
    {
        return {};
    }
    if (numRows == 1)
    {
        return {{1}};
    }
    vector<vector<int>> prev = generate(numRows - 1);
    vector<int> curr(numRows, 1);
    for (int i = 1; i < numRows - 1; i++)
    {
        curr[i] = prev.back()[i - 1] + prev.back()[i];
    }
    prev.push_back(curr);
    return prev;
}
int main()
{
    int n = 5;
    vector<vector<int>> ans = generate(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Printing particular rows..." << endl;
    for (int i = 0; i < ans[n - 1].size(); i++)
    {
        cout << ans[n - 1][i] << " ";
    }
    return 0;
}