#include <iostream>
#include <queue>
#include <stack>
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

int max_depth(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        return 0;
    }
    int left = max_depth(root->left);
    int right = max_depth(root->right);
    return max(left, right) + 1;
}

int max_depth_iterative(Node *root)
{
    // Time: O(n)
    // Space: O(n)
    int depth = 0;
    if (root == nullptr)
    {
        return depth;
    }
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == nullptr)
        {
            depth++;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    return depth;
}

int max_depth_iterative_2(Node *root)
{
    // Time: O(n)
    // Space: O(n)
    int depth = 0;
    if (root == nullptr)
    {
        return depth;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        depth++;
    }
    return depth;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << max_depth(root) << endl;
    cout << max_depth_iterative(root) << endl;
    cout << max_depth_iterative_2(root) << endl;
    return 0;
}