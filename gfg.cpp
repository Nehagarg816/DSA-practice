#include <iostream>
#include <math.h> //Decimal to bimary conversion
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1; // Reverse digit:(digit*10^i)+ans
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    cout << ans << endl;
    return 0;
}