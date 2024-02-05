#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Lowest Common Ancestor
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
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p->data or root->data == q->data)
    {
        return root;
    }
    Node *lft = lowestCommonAncestor(root->left, p, q);
    Node *rgt = lowestCommonAncestor(root->right, p, q);
    if (lft != NULL and rgt == NULL)
    {
        return lft;
    }
    if (lft == NULL and rgt != NULL)
    {
        return rgt;
    }
    if (lft == NULL and rgt == NULL)
    {
        return NULL;
    }
    else
    {
        return root;
    }
}
int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    Node *p = root->left;
    Node *q = root->left->left;
    Node *ans = lowestCommonAncestor(root, p, q);
    cout << ans->data;
    return 0;
}