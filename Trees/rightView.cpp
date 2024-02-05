#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Right View of a Binary Tree
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
    if (ans.size() == lvl)
        ans.push_back(root->data);
    solve(root->right, lvl + 1, ans);
    solve(root->left, lvl + 1, ans);
}
vector<int> rightView(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
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
    vector<int> ans = rightView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}