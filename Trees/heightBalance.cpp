#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Is Tree height Balanced or not
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
bool isHeightBalanced(Node *root)
{
    if (root == NULL or (root->left == NULL and root->right == NULL))
    {
        return true;
    }
    bool lft = isHeightBalanced(root->left);
    bool rgt = isHeightBalanced(root->right);
    bool high = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;
    if (lft and rgt and high)
    {
        return true;
    }
    return false;
}
int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    if (isHeightBalanced(root))
    {
        cout << "Tree is height balanced";
    }
    else
    {
        cout << "Tree is not height balanced";
    }
    return 0;
}