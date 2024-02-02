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

Node *lca(Node *root, int a, int b)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (a > root->data && b > root->data)
    {
        return lca(root->right, a, b);
    }
    if (a < root->data && b < root->data)
    {
        return lca(root->left, a, b);
    }
    return root;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    Node *ans = lca(root, 5, 0);
    if (ans)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << "No LCA" << endl;
    }
    return 0;
}