#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter value of left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter value of right node of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// Level Order Traversal
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Inorder Traversal
void inorder(Node *root)
{
    // LNR rule
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node *root)
{
    // NLR rule
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node *root)
{
    // LRN rule
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "enter data for root node" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
        int rightdata;
        cout << "Enter right node for " << temp->data << endl;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->left = new Node(rightdata);
            q.push(temp->left);
        }
    }
}
int main()
{
    Node *root = NULL;
    // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    // root = buildTree(root);
    LevelOrderTraversal(root);
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    return 0;
}