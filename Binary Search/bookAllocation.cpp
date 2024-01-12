#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Book Allocation Problem
bool isPossible(vector<int> &books, int m, int mid)
{
    int pageSum = 0;
    int stuCount = 1;
    for (int i = 0; i < books.size(); i++)
    {
        if (pageSum + books[i] <= mid)
        {
            pageSum += books[i];
        }
        else
        {
            stuCount++;
            pageSum = books[i];
            if (stuCount > m or books[i] > mid)
            {
                return false;
            }
        }
    }
    return true;
}
int bookAllocation(vector<int> &books, int m)
{
    int s = 0;
    int sum = 0;
    int e = accumulate(books.begin(), books.end(), 0);
    int ans = -1;
    int mid = s + (e - s) / 2;
    if (m > books.size())
    {
        return -1;
    }
    while (s <= e)
    {
        if (isPossible(books, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> books;
    int m = 2;
    books.push_back(10);
    books.push_back(20);
    books.push_back(30);
    books.push_back(40);
    cout << bookAllocation(books, m);
    return 0;
}