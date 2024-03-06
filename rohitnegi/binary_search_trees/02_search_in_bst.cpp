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

bool search(Node *root, int target)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (target < root->data)
    {
        return search(root->left, target);
    }
    return search(root->right, target);
}

int main()
{
    Node *root = nullptr;
    vector<int> arr = {20, 15, 50, 10, 18, 40, 80, 7, 12, 45};
    for (int i : arr)
    {
        root = insert_in_bst(root, i);
    }
    cout << search(root, 40) << endl;
    cout << search(root, 8) << endl;
    return 0;
}