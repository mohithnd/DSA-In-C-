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

int count_non_leaf(Node *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 0;
    }
    return 1 + count_non_leaf(root->left) + count_non_leaf(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(11);
    root->right->left->right = new Node(10);
    root->right->left->right->left = new Node(12);
    root->right->left->right->right = new Node(13);

    cout << count_non_leaf(root) << endl;
    return 0;
}