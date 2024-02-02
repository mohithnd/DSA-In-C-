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
        this->left = this->right = NULL;
    }
};

bool is_bst_helper(Node *root, long long min, long long max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data <= min || root->data >= max)
    {
        return false;
    }
    if (is_bst_helper(root->left, min, root->data) == false)
    {
        return false;
    }
    if (is_bst_helper(root->right, root->data, max) == false)
    {
        return false;
    }
    {
        return false;
    }
}

bool is_bst(Node *root)
{
    return is_bst_helper(root, -1000000000000, 1000000000000);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(6);
    root->right->left = new Node(4);
    root->right->right = new Node(8);
    cout << is_bst(root) << endl;
    return 0;
}