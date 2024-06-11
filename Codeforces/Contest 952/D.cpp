#include <iostream>
#include <vector>
using namespace std;

// Function to find the center of the Manhattan circle in the grid
pair<int, int> findCircleCenter(const vector<string> &grid, int n, int m)
{
    int minSum = n + m, maxSum = 0, minDiff = n + m, maxDiff = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '#')
            {
                int sum = i + j;
                int diff = i - j;
                if (sum < minSum)
                    minSum = sum;
                if (sum > maxSum)
                    maxSum = sum;
                if (diff < minDiff)
                    minDiff = diff;
                if (diff > maxDiff)
                    maxDiff = diff;
            }
        }
    }

    int h = (minSum + maxSum) / 2;
    int k = (minDiff + maxDiff) / 2;

    return {h + 1, k + 1};
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> grid[i];
        }

        pair<int, int> center = findCircleCenter(grid, n, m);
        cout << center.first << " " << center.second << endl;
    }

    return 0;
}
