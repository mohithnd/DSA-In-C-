#include <iostream>
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

int height(Node *root, bool &valid)
{
    if (root == nullptr)
    {
        return 0;
    }
    int l = height(root->left, valid);
    if (valid == false)
    {
        return 0;
    }
    int r = height(root->right, valid);
    if (valid == false)
    {
        return 0;
    }
    if (abs(l - r) > 1)
    {
        valid = false;
        return 0;
    }
    return 1 + max(l, r);
}

bool balanced_1(Node *root)
{
    bool valid = true;
    height(root, valid);
    return valid;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(5);
    cout << balanced_1(root) << endl;
    return 0;
}