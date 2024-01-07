#include <iostream>
#include <vector>
#include <stack>
using namespace std; // Celebrity Problem
int Celebrity(vector<vector<int>> &celeb, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (celeb[a][b] == 0)
        {
            s.push(a);
        }
        else
        {
            s.push(b);
        }
    }
    int pc = s.top();
    int one = 0;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (celeb[i][pc] == 1)
        {
            one++;
        }
        if (celeb[pc][i] == 0)
        {
            zero++;
        }
    }
    if (zero == n and one == n - 1)
    {
        return pc;
    }
    return -1;
}
int main()
{
    vector<vector<int>> celeb;
    celeb.push_back({0, 0, 1});
    celeb.push_back({0, 0, 1});
    celeb.push_back({0, 0, 0});
    int n = 3;
    cout << Celebrity(celeb, n);
    return 0;
}