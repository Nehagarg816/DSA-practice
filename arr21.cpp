#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Longest word in a word
    string str;
    getline(cin, str);
    int count = 0;
    int max = 0;
    int index = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (count > max)
            {
                max = count;
                index = i - count;
            }
            count = 0;
        }
        else
        {
            count++;
        }
    }
    if (count > max)
    {
        max = count;
        index = str.length() - count;
    }
    for (int i = index; i < index + max; i++)
    {
        cout << str[i];
    }

    return 0;
}