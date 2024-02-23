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

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->right = new Node(5);
    root->left->right->left = new Node(9);
    root->left->right->left->right = new Node(13);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);
    root->right->right = new Node(7);
    root->right->right->right = new Node(12);
    root->right->right->right->right = new Node(14);
    root->right->right->right->right->left = new Node(15);

    cout << height(root) << endl;
    return 0;
}