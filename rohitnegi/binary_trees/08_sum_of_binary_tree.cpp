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

int sum_of_binary_tree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = sum_of_binary_tree(root->left);
    int right = sum_of_binary_tree(root->right);
    return root->data + left + right;
}

int main()
{
    Node *root = new Node(3);
    root->right = new Node(1);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    root->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    cout << sum_of_binary_tree(root) << endl;
    return 0;
}