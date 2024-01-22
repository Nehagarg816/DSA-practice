#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int diff = prices[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, prices[i]);
    }
    return profit;
}
int main()
{
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    cout << maxProfit(prices);
    return 0;
}