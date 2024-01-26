#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    queue<int> q;
    q.push(0);
    vector<bool> vis(rooms.size(), 0);
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        vis[frontNode] = 1;
        for (int i = 0; i < rooms[frontNode].size(); i++)
        {
            if (!vis[rooms[frontNode][i]])
            {
                q.push(rooms[frontNode][i]);
            }
        }
    }
    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> rooms;
    rooms.push_back({1});
    rooms.push_back({2});
    rooms.push_back({3});
    rooms.push_back({0});
    cout << canVisitAllRooms(rooms);
    return 0;
}