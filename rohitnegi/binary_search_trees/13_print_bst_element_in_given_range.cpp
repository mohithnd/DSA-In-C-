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

void find_path(Node *root, int val, vector<Node *> &v)
{
    if (root == nullptr)
    {
        return;
    }
    v.push_back(root);
    if (root->data == val)
    {
        return;
    }
    if (val < root->data)
    {
        find_path(root->left, val, v);
    }
    else
    {
        find_path(root->right, val, v);
    }
}

void inorder_2(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }
    inorder_2(root->left, arr);
    arr.push_back(root->data);
    inorder_2(root->right, arr);
}

void print_in_range_1(Node *root, int l, int u)
{
    vector<int> arr;
    inorder_2(root, arr);
    for (int i : arr)
    {
        if (i > l && i < u)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void print_in_range_2(Node *root, int l, int u)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data > u)
    {
        print_in_range_2(root->left, l, u);
    }
    else if (root->data < l)
    {
        print_in_range_2(root->right, l, u);
    }
    else
    {
        print_in_range_2(root->left, l, u);
        cout << root->data << " ";
        print_in_range_2(root->right, l, u);
    }
}

int main()
{
    vector<int> arr = {100, 85, 200, 30, 90, 180, 300, 20, 70, 68, 74, 65, 72, 81};
    Node *root = nullptr;
    for (int i : arr)
    {
        root = insert_in_bst(root, i);
    }
    print_in_range_1(root, 60, 80);
    print_in_range_2(root, 60, 80);
    return 0;
}