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

int ceil_in_bst(Node *root, int key)
{
    // time complexity: O(logn)
    // space complexity: O(1)
    int ans = -1;
    while (root)
    {
        if (root->data == key)
        {
            ans = root->data;
            break;
        }
        if (key < root->data)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    cout << ceil_in_bst(root, 8) << endl;
    return 0;
}