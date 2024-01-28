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

bool is_symmetric(Node *root1, Node *root2)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n) (for recursive stack)
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    if (is_symmetric(root1->left, root2->right) == false)
    {
        return false;
    }
    if (is_symmetric(root1->right, root2->left) == false)
    {
        return false;
    }
    return true;
}

bool is_symmetric_2(Node *root1)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    if (root1 == nullptr)
    {
        return true;
    }
    stack<Node *> s;
    s.push(root1->left);
    s.push(root1->right);
    while (!s.empty())
    {
        Node *node1 = s.top();
        s.pop();
        Node *node2 = s.top();
        s.pop();
        if (node1 == nullptr && node2 == nullptr)
        {
            continue;
        }
        if (node1 == nullptr || node2 == nullptr)
        {
            return false;
        }
        if (node1->data != node2->data)
        {
            return false;
        }
        s.push(node1->left);
        s.push(node2->right);
        s.push(node1->right);
        s.push(node2->left);
    }
    return true;
}

bool is_symmetric_3(Node *root)
{
    // time complexity: O(n)
    // space complexity: O(n)
    if (root == nullptr)
    {
        return true;
    }
    queue<Node *> q;
    q.push(root);
    q.push(root);
    while (!q.empty())
    {
        Node *node1 = q.front();
        q.pop();
        Node *node2 = q.front();
        q.pop();
        if (node1 == nullptr && node2 == nullptr)
        {
            continue;
        }
        if (node1 == nullptr || node2 == nullptr)
        {
            return false;
        }
        if (node1->data != node2->data)
        {
            return false;
        }
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }
    return true;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    cout << is_symmetric(root, root) << endl;
    cout << is_symmetric_2(root) << endl;
    cout << is_symmetric_3(root) << endl;
    return 0;
}