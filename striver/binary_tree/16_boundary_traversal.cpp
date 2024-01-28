#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
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

void left(Node *root, vector<int> &res)
{
    // time: O(n)
    // space: O(h) - recursion stack
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    res.push_back(root->data);
    if (root->left)
    {
        left(root->left, res);
    }
    else if (root->right)
    {
        left(root->right, res);
    }
}

void leaf(Node *root, vector<int> &res)
{
    // time: O(n)
    // space: O(h) - recursion stack
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        res.push_back(root->data);
        return;
    }
    leaf(root->left, res);
    leaf(root->right, res);
}

void right(Node *root, vector<int> &res)
{
    // time: O(n)
    // space: O(h) - recursion stack
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    if (root->right)
    {
        right(root->right, res);
    }
    else if (root->left)
    {
        right(root->left, res);
    }
    res.push_back(root->data);
}

void boundary_traversal(Node *root)
{
    // time: O(n)
    // space: O(h) - recursion stack
    vector<int> res;
    if (root == NULL)
    {
        return;
    }
    res.push_back(root->data);
    left(root->left, res);
    leaf(root, res);
    right(root->right, res);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

bool is_leaf(Node *root)
{
    return root->left == nullptr && root->right == nullptr;
}

void add_left(Node *root, vector<int> &res)
{
    // time: O(n)
    // space: O(1)
    while (root)
    {
        if (!is_leaf(root))
        {
            res.push_back(root->data);
        }
        if (root->left)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

void add_leaf(Node *root, vector<int> &res)
{
    // time: O(n)
    // space: O(h) - recursion stack
    if (root == nullptr)
    {
        return;
    }
    if (is_leaf(root))
    {
        res.push_back(root->data);
        return;
    }
    add_leaf(root->left, res);
    add_leaf(root->right, res);
}

void add_right(Node *root, vector<int> &res)
{
    // time: O(n)
    // space: O(n)
    stack<int> s;
    while (root)
    {
        if (!is_leaf(root))
        {
            s.push(root->data);
        }
        if (root->right)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
}

void boundary_traversal_iterative(Node *root)
{
    // time: O(n)
    // space: O(h) - recursion stack
    if (root == nullptr)
    {
        return;
    }
    vector<int> res;
    res.push_back(root->data);
    add_left(root->left, res);
    add_leaf(root, res);
    add_right(root->right, res);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->left->right->left = new Node(7);
    root->right->left = new Node(18);
    root->right->right = new Node(25);

    boundary_traversal(root);
    boundary_traversal_iterative(root);
    return 0;
}