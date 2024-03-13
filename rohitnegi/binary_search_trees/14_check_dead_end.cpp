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

Node *insert_in_bst(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert_in_bst(root->left, data);
    }
    else
    {
        root->right = insert_in_bst(root->right, data);
    }
    return root;
}

bool solve(Node *root, int lower, int upper)
{
    if (root == nullptr)
    {
        return false;
    }
    if (!root->left && !root->right)
    {
        if (root->data - lower == 1 && upper - root->data == 1)
        {
            return true;
        }
        return false;
    }
    bool left = solve(root->left, lower, root->data);
    if (left)
    {
        return true;
    }
    return solve(root->right, root->data, upper);
}

bool dead_end(Node *root)
{
    return solve(root, 0, INT_MAX);
}

int main()
{
    vector<int> arr = {20, 15, 22, 10, 18, 21, 26};
    Node *root = nullptr;
    for (int i : arr)
    {
        root = insert_in_bst(root, i);
    }
    vector<int> arr2 = {20, 15, 24, 10, 19, 6, 11};
    Node *root2 = nullptr;
    for (int i : arr2)
    {
        root2 = insert_in_bst(root2, i);
    }
    cout << dead_end(root) << endl;
    cout << dead_end(root2) << endl;
    return 0;
}