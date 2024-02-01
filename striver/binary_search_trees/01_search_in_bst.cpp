#include <iostream>
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

Node *search_in_bst(Node *root, int key)
{
    // tc : O(logn)
    // sc : O(1)
    while (root != nullptr && root->data != key)
    {
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}

Node *search_in_bst_recursive(Node *root, int key)
{
    // tc : O(logn)
    // sc : O(logn)
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search_in_bst_recursive(root->left, key);
    }
    return search_in_bst_recursive(root->right, key);
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right = new Node(12);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    cout << search_in_bst(root, 10) << endl;
    cout << search_in_bst(root, 100) << endl;
    cout << search_in_bst_recursive(root, 10) << endl;
    cout << search_in_bst_recursive(root, 100) << endl;
    return 0;
}