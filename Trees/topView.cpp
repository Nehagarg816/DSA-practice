#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Top View of a Binary Tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void solve(Node *root, int lvl, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, lvl});
    while (!q.empty())
    {
        auto it = q.front();
        Node *frontNode = it.first;
        int val = it.second;
        q.pop();
        if (m.find(val) == m.end())
        {
            m[val] = frontNode->data;
        }
        if (frontNode->left)
        {
            q.push({frontNode->left, val - 1});
        }
        if (frontNode->right)
        {
            q.push({frontNode->right, val + 1});
        }
    }
    for (auto x : m)
    {
        ans.push_back(x.second);
    }
}
vector<int> topView(Node *root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}
int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    vector<int> v = topView(root);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}