#include <iostream>
#include <queue>
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

int count_total_nodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + count_total_nodes(root->left) + count_total_nodes(root->right);
}

bool is_cbt(Node *root, int ind, int total_nodes)
{
    if (root == nullptr)
    {
        return true;
    }
    if (ind >= total_nodes)
    {
        return false;
    }
    bool left = is_cbt(root->left, 2 * ind + 1, total_nodes);
    if (left == false)
    {
        return false;
    }
    return is_cbt(root->right, 2 * ind + 2, total_nodes);
}

bool solve(Node *root)
{
    if (root->left)
    {
        if (root->left->data > root->data)
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
        if (root->right->data > root->data)
        {
            return false;
        }
        bool right = solve(root->right);
        if (right == false)
        {
            return false;
        }
    }
    return true;
}

bool is_max_heap_1(Node *root)
{
    int total_nodes = count_total_nodes(root);
    bool cbt = is_cbt(root, 0, total_nodes);
    if (cbt == false)
    {
        return false;
    }
    return solve(root);
}

bool is_max_heap_2(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int node_count = 0;
    while (!q.empty())
    {
        Node *curr = q.front().first;
        int ind = q.front().second;
        q.pop();
        node_count++;
        if (ind >= node_count)
        {
            return false;
        }
        if (curr->left)
        {
            if (curr->left->data > curr->data)
            {
                return false;
            }
            q.push({curr->left, ind * 2 + 1});
        }
        if (curr->right)
        {
            if (curr->right->data > curr->data)
            {
                return false;
            }
            q.push({curr->right, ind * 2 + 2});
        }
    }
    return true;
}

int main()
{
    Node *t1 = new Node(80);
    t1->left = new Node(60);
    t1->right = new Node(70);
    t1->left->left = new Node(40);
    t1->left->right = new Node(30);
    cout << is_max_heap_1(t1) << endl;
    cout << is_max_heap_2(t1) << endl;

    Node *t2 = new Node(90);
    t2->left = new Node(80);
    t2->right = new Node(70);
    t2->left->left = new Node(40);
    t2->left->right = new Node(20);
    t2->right->right = new Node(60);
    cout << is_max_heap_1(t2) << endl;
    cout << is_max_heap_2(t2) << endl;
    return 0;
}