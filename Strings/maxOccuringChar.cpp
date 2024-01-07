#include <iostream>
using namespace std; // MAximum Occurring Character in String
char maxOccurCharacter(string &s)
{
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int number = 0;
        if (s[i] >= 'a' and s[i] <= 'z')
        {
            number = s[i] - 'a';
        }
        if (s[i] >= 'A' and s[i] <= 'Z')
        {
            number = s[i] - 'A';
        }
        arr[number]++;
    }
    int maxi = -1;
    char ans;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxi)
        {
            ans = i;
            maxi = arr[i];
        }
    }
    ans = 'a' + ans;
    return ans;
}
int main()
{
    string s = "output";
    cout << maxOccurCharacter(s);
    return 0;
}