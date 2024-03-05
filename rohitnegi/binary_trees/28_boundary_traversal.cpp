#include <iostream>
#include <vector>
#include <queue>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

void left_most(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        left_most(root->left, ans);
    }
    else
    {
        left_most(root->right, ans);
    }
}

void right_most(Node *root, vector<int> &ans)
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
        left_most(root->right, ans);
    }
    else
    {
        left_most(root->left, ans);
    }
    ans.push_back(root->data);
}

void leaves(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
        return;
    }
    leaves(root->left, ans);
    leaves(root->right, ans);
}

void boundary(Node *root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    vector<int> ans;
    left_most(root, ans);
    leaves(root, ans);
    right_most(root->right, ans);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    boundary(root);
    return 0;
}