#include <iostream>
using namespace std;

int main()
{
    int arr[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}