#include <bits/stdc++.h>
using namespace std;
string solve(int n, vector<int> &arr)
{
    string ans = "";
    int letter[26] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (arr[i] == letter[j])
            {
                char c = j + 'a';
                ans += c;
                letter[j]++;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(n, arr) << endl;
    }
}