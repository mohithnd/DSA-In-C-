#include <iostream>
#include <queue>
#include <vector>
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

int solve(Node *root, int &k)
{
    if (root == nullptr)
    {
        return -1;
    }
    int right = solve(root->right, k);
    if (right != -1)
    {
        return right;
    }
    k--;
    if (k == 0)
    {
        return root->data;
    }
    return solve(root->left, k);
}

int kth_largest(Node *root, int k)
{
    return solve(root, k);
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->left->left = new Node(6);
    root->left->right = new Node(24);
    root->right = new Node(40);
    root->right->left = new Node(36);
    root->right->right = new Node(50);
    root->right->right->left = new Node(45);
    cout << kth_largest(root, 3) << endl;
    return 0;
}