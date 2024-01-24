#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int pseudoPalindromicPaths(Node *root)
{
    int count = 0;
    int path = 0;
    stack<pair<Node *, int>> s;
    s.push({root, 0});
    while (!s.empty())
    {
        auto top = s.top();
        s.pop();
        Node *node = top.first;
        path = top.second;
        if (node)
        {
            path ^= (1 << node->data);
            if (!node->left and !node->right)
            {
                if ((path & (path - 1)) == 0)
                {
                    ++count;
                }
            }
            else
            {
                s.push({node->left, path});
                s.push({node->right, path});
            }
        }
    }
    return count;
}
int main()
{
    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(1);
    root->left->left = new Node(3);
    root->left->right = new Node(1);
    root->right->right = new Node(1);
    cout << pseudoPalindromicPaths(root);
    return 0;
}