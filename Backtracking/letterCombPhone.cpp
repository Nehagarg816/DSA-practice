#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(string digits, int index, string mapping[], vector<string> &ans, string out)
{
    if (index >= digits.length())
    {
        ans.push_back(out);
        return;
    }
    int dig = digits[index] - '0';
    string letter = mapping[dig];
    for (int i = 0; i < letter.length(); i++)
    {
        out.push_back(letter[i]);
        solve(digits, index + 1, mapping, ans, out);
        out.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.length() == 0)
    {
        return {};
    }
    vector<string> ans;
    string out = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, 0, mapping, ans, out);
    return ans;
}
int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}