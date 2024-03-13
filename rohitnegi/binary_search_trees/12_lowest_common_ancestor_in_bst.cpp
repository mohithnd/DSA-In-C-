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

Node *lca_1(Node *root, int n1, int n2)
{
    vector<Node *> a;
    find_path(root, n1, a);
    vector<Node *> b;
    find_path(root, n2, b);
    int i = 0;
    while (i < a.size() && i < b.size())
    {
        if (a[i] != b[i])
        {
            return a[i - 1];
        }
        i++;
    }
    if (i < a.size())
    {
        return b[i - 1];
    }
    return a[i - 1];
}

Node *lca_2(Node *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (n1 < root->data && n2 < root->data)
    {
        return lca_2(root->left, n1, n2);
    }
    else if (n1 > root->data && n2 > root->data)
    {
        return lca_2(root->right, n1, n2);
    }
    return root;
}

int main()
{
    vector<int> arr = {50, 18, 70, 10, 30, 65, 80, 28, 40, 95, 20, 35, 45};
    Node *root = nullptr;
    for (int i : arr)
    {
        root = insert_in_bst(root, i);
    }
    cout << lca_1(root, 20, 40)->data << endl;
    cout << lca_2(root, 20, 40)->data << endl;
    return 0;
}