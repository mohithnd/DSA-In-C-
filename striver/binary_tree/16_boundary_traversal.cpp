#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void left(Node *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    res.push_back(root->data);
    if (root->left)
    {
        left(root->left, res);
    }
    else if (root->right)
    {
        left(root->right, res);
    }
}

void leaf(Node *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        res.push_back(root->data);
        return;
    }
    leaf(root->left, res);
    leaf(root->right, res);
}

void right(Node *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    if (root->right)
    {
        right(root->right, res);
    }
    else if (root->left)
    {
        right(root->left, res);
    }
    res.push_back(root->data);
}

void boundary_traversal(Node *root)
{
    vector<int> res;
    if (root == NULL)
    {
        return;
    }
    res.push_back(root->data);
    left(root->left, res);
    leaf(root, res);
    right(root->right, res);
    for (int i : res)
    {
        cout << i << " ";
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->left->right->left = new Node(7);
    root->right->left = new Node(18);
    root->right->right = new Node(25);

    boundary_traversal(root);
    return 0;
}