#include <iostream>
#include <bits/stdc++.h>
using namespace std; // Total possible paths in a binary tree
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
void possiblePaths(Node *root, vector<int> &currentPath, vector<vector<int>> &paths)
{
    if (root == NULL)
    {
        return;
    }

    currentPath.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        paths.push_back(currentPath);
    }

    possiblePaths(root->left, currentPath, paths);
    possiblePaths(root->right, currentPath, paths);

    // Backtrack: remove the current node from the path
    currentPath.pop_back();
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    vector<vector<int>> paths;
    vector<int> currentPath;

    possiblePaths(root, currentPath, paths);
    for (int i = 0; i < paths.size(); i++)
    {
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}