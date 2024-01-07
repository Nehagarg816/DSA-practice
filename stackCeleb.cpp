#include <iostream>
#include <stack>
#include <vector>
using namespace std; // Celebrity Problem
class Solution
{
private:
    bool Knows(vector<vector<int>> &M, int a, int b, int n)
    {
        if (M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;               // Create a stack
        for (int i = 0; i < n; i++) // push all the elements in the stack
        {
            s.push(i);
        }
        while (s.size() > 1)
        {
            // pop top two elements from the stack and compare them
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (Knows(M, a, b, n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        // single element in the stack is the potential celebrity
        int pot = s.top();
        int zeroCount = 0;
        // Row check
        for (int i = 0; i < n; i++)
        {
            if (M[pot][i] == 0)
                zeroCount++;
        }
        int oneCount = 0;
        // Column check
        for (int i = 0; i < n; i++)
        {
            if (M[i][pot] == 1)
            {
                oneCount++;
            }
        }
        if (zeroCount == n && oneCount == n - 1)
        {
            return pot;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    Solution obj;
    cout << obj.celebrity(M, n) << endl;
    return 0;
}