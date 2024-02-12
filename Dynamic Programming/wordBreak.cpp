#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
bool solve(int start, string s, unordered_set<string> &dictionary)
{
    if (start == s.length())
    {
        return true;
    }
    bool ans = false;
    for (int end = start; end < s.length(); end++)
    {
        if (dictionary.count(s.substr(start, end - start + 1)) and solve(end + 1, s, dictionary))
        {
            ans = true;
        }
    }
    return ans;
}
bool solveMemo(int start, string s, unordered_set<string> &dictionary, vector<int> &dp)
{
    if (start == s.length())
    {
        return true;
    }
    if (dp[start] != -1)
    {
        return dp[start];
    }
    for (int end = start; end < s.length(); end++)
    {
        if (dictionary.count(s.substr(start, end - start + 1)) and solveMemo(end + 1, s, dictionary, dp))
        {
            dp[start] = 1;
            return true;
        }
    }
    return dp[start] = false;
}
bool solveTab(unordered_set<string> &dictionary, string s)
{
    vector<int> dp(s.length() + 1, 0);
    int n = s.length();
    dp[n] = 1;
    for (int start = n - 1; start >= 0; start--)
    {
        for (int end = start; end < s.length(); end++)
        {
            if (dictionary.count(s.substr(start, end - start + 1)) and dp[end + 1])
            {
                dp[start] = 1;
            }
        }
    }
    return dp[0];
}
int main()
{
    vector<string> wordDict = {"cat", "cats", "sand", "and", "dog"};
    string s = "catsanddog";
    vector<int> dp(s.size(), -1);
    unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
    cout << solve(0, s, dictionary) << endl;         // Recursion
    cout << solveMemo(0, s, dictionary, dp) << endl; // Memoization
    cout << solveTab(dictionary, s) << endl;         // Tabulation
    return 0;
}