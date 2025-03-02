#include <iostream>
#include <bits/stdc++.h>
using namespace std; // insertion in Binary Search Tree
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
// insertion in binary search tree
void insertion(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    if (val < root->data)
    {
        if (root->left == NULL)
        {
            root->left = new Node(val);
        }
        else
        {
            insertion(root->left, val);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(val);
        }
        else
        {
            insertion(root->right, val);
        }
    }
}
// printing the bst
void printBst(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printBst(root->left);
    cout << root->data << " ";
    printBst(root->right);
}
int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    insertion(root, 6);
    printBst(root);
    return 0;
}