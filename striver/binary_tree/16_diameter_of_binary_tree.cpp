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

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);
    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);
    int current_diameter = left_depth + right_depth + 1;
    return max(current_diameter, max(left_diameter, right_diameter));
    return 0;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    cout << diameter(root) << endl;
    return 0;
}