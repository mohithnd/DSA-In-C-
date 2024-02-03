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

void mark_parents(Node *root, map<Node *, Node *> &parents)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
            parents[node->left] = node;
        }
        if (node->right)
        {
            q.push(node->right);
            parents[node->right] = node;
        }
    }
}

Node *find_node(Node *root, int target)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == target)
    {
        return root;
    }
    Node *left = find_node(root->left, target);
    if (left)
    {
        return left;
    }
    Node *right = find_node(root->right, target);
    if (right)
    {
        return right;
    }
    return nullptr;
}

void print_nodes_at_distance_k(Node *root, int k, int target)
{
    if (root == nullptr)
    {
        cout << endl;
        return;
    }
    map<Node *, Node *> parents;
    mark_parents(root, parents);
    Node *target_node = find_node(root, target);
    map<Node *, bool> visited;
    queue<pair<Node *, int>> q;
    q.push({target_node, 0});
    visited[target_node] = true;
    while (!q.empty())
    {
        Node *node = q.front().first;
        int dis = q.front().second;
        q.pop();
        if (dis == k)
        {
            cout << node->data << " ";
        }
        if (node->left && visited[node->left] == false)
        {
            q.push({node->left, dis + 1});
            visited[node->left] = true;
        }
        if (node->right && visited[node->right] == false)
        {
            q.push({node->right, dis + 1});
            visited[node->right] = true;
        }
        if (parents[node] && visited[parents[node]] == false)
        {
            q.push({parents[node], dis + 1});
            visited[parents[node]] = true;
        }
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    print_nodes_at_distance_k(root, 2, 5);
    return 0;
}