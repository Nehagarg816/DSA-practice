#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int ans[t];
    for (int x = 0; x < t; x++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> freqMap; // Map to store element frequencies

        // Count the frequency of each element
        for (int i = 0; i < n; i++)
        {
            freqMap[arr[i]]++;
        }

        int maxFreq = 0;                  // Maximum frequency
        int maxOccurringElement = arr[0]; // Element with maximum frequency

        // Find the element with maximum frequency
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
        {
            if (it->second > maxFreq)
            {
                maxFreq = it->second;
                maxOccurringElement = it->first;
            }
        }

        int i = 0;
        int count = 0;
        while (i < n)
        {
            if (arr[i] == maxOccurringElement)
            {
                i++;
            }
            else
            {
                arr[i] = maxOccurringElement;
                count++;
                i++;
            }
        }
        ans[x] = count;
    }
    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}