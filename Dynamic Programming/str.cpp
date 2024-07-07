#include <bits/stdc++.h>
using namespace std;
bool static cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

int solve(string &target, int index, vector<pair<string, int>> &word, unordered_map<int, int> &memo)
{
    if (index == target.length())
        return 0;
    if (memo.find(index) != memo.end())
        return memo[index];

    int minCost = INT_MAX;

    for (auto &w : word)
    {
        int len = w.first.length();
        if (index + len <= target.length() && target.substr(index, len) == w.first)
        {
            int cost = solve(target, index + len, word, memo);
            if (cost != -1)
            {
                minCost = min(minCost, cost + w.second);
            }
        }
    }

    memo[index] = (minCost == INT_MAX) ? -1 : minCost;
    return memo[index];
}

int minimumCost(string target, vector<string> &words, vector<int> &costs)
{
    vector<pair<string, int>> word;
    int n = words.size();
    for (int i = 0; i < n; ++i)
    {
        word.push_back({words[i], costs[i]});
    }
    sort(word.begin(), word.end(), cmp);

    unordered_map<int, int> memo;
    return solve(target, 0, word, memo);
}

int main()
{
    string target = "aaaa";
    vector<string> words = {"z", "zz", "zzz"};
    vector<int> costs = {1, 10, 100};
    int result = minimumCost(target, words, costs);
    cout << result;
    return 0;
}
