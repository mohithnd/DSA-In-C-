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

Node *kth_smallest_helper(Node *root, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *left = kth_smallest_helper(root->left, k);
    if (left != NULL)
    {
        return left;
    }
    k--;
    if (k == 0)
    {
        return root;
    }
    return kth_smallest_helper(root->right, k);
}

int kth_smallest(Node *root, int k)
{
    Node *ans = kth_smallest_helper(root, k);
    if (ans == NULL)
    {
        return -1;
    }
    return ans->data;
}

Node *kth_largest_helper(Node *root, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *right = kth_largest_helper(root->right, k);
    if (right != NULL)
    {
        return right;
    }
    k--;
    if (k == 0)
    {
        return root;
    }
    return kth_largest_helper(root->left, k);
}

int kth_largest(Node *root, int k)
{
    Node *ans = kth_largest_helper(root, k);
    if (ans == NULL)
    {
        return -1;
    }
    return ans->data;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->left->right = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    cout << kth_smallest(root, 3) << endl;
    cout << kth_largest(root, 3) << endl;
    return 0;
}