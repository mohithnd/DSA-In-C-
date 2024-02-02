#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
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

void level_order(Node *root)
{
    // TC: O(n)
    // SC: O(n)
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        res.push_back(temp);
    }
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

bool is_children_sum_tree(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (is_children_sum_tree(root->left) == false)
    {
        return false;
    }
    if (is_children_sum_tree(root->right) == false)
    {
        return false;
    }
    int sum = 0;
    if (root->left)
    {
        sum += root->left->data;
    }
    if (root->right)
    {
        sum += root->right->data;
    }
    if (sum != 0 && sum != root->data)
    {
        return false;
    }
    return true;
}

void make_children_sum_tree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    make_children_sum_tree(root->left);
    make_children_sum_tree(root->right);
    if (root->left && root->right)
    {
        int sum = root->left->data + root->right->data;
        if (sum > root->data)
        {
            root->data = sum;
        }
        else if (sum < root->data)
        {
            int diff = root->data - sum;
            root->left->data += diff;
        }
    }
    else
    {
        if (root->left)
        {
            if (root->left->data > root->data)
            {
                root->data = root->left->data;
            }
            else if (root->left->data < root->data)
            {
                root->left->data = root->data;
            }
        }
        else
        {
            if (root->right->data > root->data)
            {
                root->data = root->right->data;
            }
            else if (root->right->data < root->data)
            {
                root->right->data = root->data;
            }
        }
    }
}

int main()
{
    Node *root = new Node(40);
    root->left = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(40);
    cout << "Before Conversion:-" << endl;
    level_order(root);
    cout << is_children_sum_tree(root) << endl;

    cout << endl;
    make_children_sum_tree(root);

    cout << "After Conversion:-" << endl;
    level_order(root);
    cout << is_children_sum_tree(root) << endl;
    return 0;
}