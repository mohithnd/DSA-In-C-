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

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

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

Node *delete_node(Node *root, int target)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (target < root->data)
    {
        root->left = delete_node(root->left, target);
        return root;
    }
    else if (target > root->data)
    {
        root->right = delete_node(root->right, target);
        return root;
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left && root->right)
        {
            Node *child = root->left;
            Node *parent = root;
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            if (parent != root)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
        else if (root->left)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
    }
}

int main()
{
    Node *root = nullptr;
    vector<int> arr = {20, 15, 50, 10, 18, 40, 80, 7, 12, 17, 19, 45, 60, 90, 11, 14, 55, 85, 100, 42, 58, 95};
    for (int i : arr)
    {
        root = insert_in_bst(root, i);
    }
    inorder(root);
    cout << endl;
    root = delete_node(root, 7);
    root = delete_node(root, 40);
    root = delete_node(root, 100);
    root = delete_node(root, 15);
    inorder(root);
    cout << endl;
    return 0;
}