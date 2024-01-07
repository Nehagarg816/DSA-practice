#include <iostream>
#include <string>
using namespace std; // Permutations in String
bool checkEqual(int arr[], int arr2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
bool CheckPermutations(string &s1, string &s2)
{
    // store character array
    int arr[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        arr[index]++;
    }
    // traverse s2 string in windows of size s1.length and compare
    int i = 0;
    int windowSize = s1.length();
    int arr2[26] = {0};

    // Run for first window
    while (i < windowSize and i < s2.length())
    {
        int index = s2[i] - 'a';
        arr2[index]++;
        i++;
    }

    // Compare for first window
    if (checkEqual(arr, arr2))
    {
        return true;
    }

    // traverse for other windows
    while (i < s2.length())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        arr2[index]++;
        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        arr2[index]--;
        i++;
        // compare for other windows
        if (checkEqual(arr, arr2))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << CheckPermutations(s1, s2);
    return 0;
}