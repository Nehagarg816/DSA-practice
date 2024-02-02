#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(long long num)
{
    bool valid = false;
    while (num != 0)
    {
        int a = num % 10;
        num = num / 10;
        if (num == 0)
        {
            break;
        }
        int b = num % 10;
        if ((b + 1) == a)
        {
            valid = true;
        }
        else
        {
            valid = false;
            break;
        }
    }
    return valid;
}
vector<int> sequentialDigits(int low, int high) // Brute Force Approach
{
    vector<int> ans;
    for (long long i = low; i <= high; i++)
    {
        if (check(i) == true)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> sequentialDigits2(int low, int high) // Optimized Approach
{
    vector<int> ans;
    for (int i = 1; i <= 9; i++)
    {
        int dig = i;
        int nextdig = i + 1;
        while (nextdig <= 9 and dig <= high)
        {
            dig = dig * 10 + nextdig;
            if (low <= dig and dig <= high)
            {
                ans.push_back(dig);
            }
            nextdig++;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int low = 100;
    int high = 300;
    vector<int> ans = sequentialDigits(low, high);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    ans = sequentialDigits2(low, high);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}