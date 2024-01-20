#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Total subsequences in an array
void subsequences(vector<int> &v, int n)
{
    int opsize = pow(2, n);
    vector<vector<int>> subsequence;
    for (int i = 1; i < opsize; i++)
    {
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                vec.push_back(v[j]);
            }
        }
        subsequence.push_back(vec);
    }
    for (int i = 0; i < subsequence.size(); i++)
    {
        for (int j = 0; j < subsequence[i].size(); j++)
        {
            cout << subsequence[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    subsequences(v, v.size());
    return 0;
}