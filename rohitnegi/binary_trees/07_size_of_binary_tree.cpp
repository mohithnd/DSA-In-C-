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

int size_of_binary_tree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = size_of_binary_tree(root->left);
    int right = size_of_binary_tree(root->right);
    return 1 + left + right;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(5);
    root->left->left->left = new Node(7);
    root->left->right = new Node(6);
    root->left->right->left = new Node(8);
    root->right = new Node(3);
    root->right->right = new Node(9);
    root->right->left = new Node(4);
    root->right->left->right = new Node(11);

    cout << size_of_binary_tree(root) << endl;
    return 0;
}