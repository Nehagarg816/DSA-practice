#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; // Max Frequency of an element in an array

void maxFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (count[arr[i]] == maxFreq)
        {
            maxAns = arr[i];
            break;
        }
    }
    cout << maxAns << " - " << maxFreq << endl;
}
int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(3);
    int n = 6;
    maxFrequency(arr, n);
    return 0;
}