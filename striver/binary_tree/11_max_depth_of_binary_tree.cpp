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

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << max_depth(root) << endl;
    return 0;
}