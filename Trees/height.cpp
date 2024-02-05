#include <iostream>
#include <bits/stdc++.h>
using namespace std; // height of a Binary Tree
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
int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    int lft = heightOfTree(root->left);
    int rgt = heightOfTree(root->right);
    ans = max(lft, rgt) + 1;
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
    cout << heightOfTree(root);
    return 0;
}