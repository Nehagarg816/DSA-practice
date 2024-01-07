#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int segment(int x, vector<int> space)
{
    int maxMinSpace = 0;
    int minSpace = INT_MAX;

    for (int i = 0; i < space.size(); ++i)
    {
        if (i >= x)
        {
            maxMinSpace = max(maxMinSpace, minSpace);
            minSpace = space[i - x + 1];
        }
        minSpace = min(minSpace, space[i]);
    }

    maxMinSpace = max(maxMinSpace, minSpace);

    return maxMinSpace;
}

int main()
{
    int x = 2;
    vector<int> space = {8, 2, 4, 6};

    cout << "Output: " << segment(x, space) << endl;

    return 0;
}
