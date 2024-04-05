#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kth_smallest_element(vector<int> arr, int k)
{
    priority_queue<int> q;
    for (int i : arr)
    {
        if (q.size() < k)
        {
            q.push(i);
        }
        else
        {
            if (i < q.top())
            {
                q.pop();
                q.push(i);
            }
        }
    }
    return q.top();
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

int count_nodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

bool is_cbt(Node *root, int i, int total_nodes)
{
    if (root == nullptr)
    {
        return true;
    }
    if (i >= total_nodes)
    {
        return false;
    }
    bool left = is_cbt(root->left, 2 * i + 1, total_nodes);
    if (left == false)
    {
        return false;
    }
    return is_cbt(root->right, 2 * i + 2, total_nodes);
}

bool solve(Node *root)
{
    if (root->left)
    {
        if (root->left->data >= root->data)
        {
            return false;
        }
        bool left = solve(root->left);
        if (left == false)
        {
            return false;
        }
    }
    if (root->right)
    {
        if (root->right->data >= root->data)
        {
            return false;
        }
        return solve(root->right);
    }
    return true;
}

bool is_binary_tree_max_heap(Node *root)
{
    int count = count_nodes(root);
    bool cbt = is_cbt(root, 0, count);
    if (cbt == false)
    {
        return false;
    }
    return solve(root);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << is_binary_tree_max_heap(root) << endl;
    return 0;
}