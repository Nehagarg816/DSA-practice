#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int ans = 0;
    queue<pair<int, int>> monthly;
    queue<pair<int, int>> weekly;
    for (int day : days)
    {
        while (monthly.size() > 0 and monthly.front().first + 30 <= day)
        {
            monthly.pop();
        }
        while (weekly.size() > 0 and weekly.front().first + 7 <= day)
        {
            weekly.pop();
        }
        monthly.push({day, ans + costs[2]});
        weekly.push({day, ans + costs[1]});
        ans = min(ans + costs[0], min(monthly.front().second, weekly.front().second));
    }
    return ans;
}
int main()
{
    vector<int> days;
    vector<int> costs;
    days.push_back(2);
    days.push_back(5);
    costs.push_back(1);
    costs.push_back(4);
    costs.push_back(25);
    cout << mincostTickets(days, costs) << endl;
    return 0;
}