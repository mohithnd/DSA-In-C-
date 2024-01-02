#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int max_depth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = max_depth(root->left);
    int right = max_depth(root->right);
    return max(left, right) + 1;
}

bool is_balanced(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    bool left = is_balanced(root->left);
    if (left == false)
    {
        return false;
    }
    bool right = is_balanced(root->right);
    if (right == false)
    {
        return false;
    }
    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);
    if (abs(left_depth - right_depth) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_balanced_2(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = is_balanced_2(root->left);
    if (left == -1)
    {
        return -1;
    }
    int right = is_balanced_2(root->right);
    if (right == -1)
    {
        return -1;
    }
    if (abs(left - right) > 1)
    {
        return -1;
    }
    return max(left, right) + 1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << is_balanced(root) << endl;
    cout << is_balanced_2(root) << endl;
    return 0;
}