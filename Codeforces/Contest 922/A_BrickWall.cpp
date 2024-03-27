#include <iostream>
using namespace std; // A- Brick Wall Codeforces problem
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << (m / 2) * n << endl;
    }
    return 0;
}