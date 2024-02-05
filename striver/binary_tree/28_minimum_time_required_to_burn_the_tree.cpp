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

Node *bfs_to_map_parents_and_find_node(Node *root, map<Node *, Node *> &parents, int target)
{
    Node *node = nullptr;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->data == target)
        {
            node = curr;
        }
        if (curr->left)
        {
            q.push(curr->left);
            parents[curr->left] = curr;
        }
        if (curr->right)
        {
            q.push(curr->right);
            parents[curr->right] = curr;
        }
    }
    return node;
}

int minimum_time_required_to_burn(Node *root, int target)
{
    if (root == nullptr)
    {
        return 0;
    }
    map<Node *, Node *> parents;
    Node *target_node = bfs_to_map_parents_and_find_node(root, parents, target);
    int ans = 0;
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target_node);
    visited[target_node] = true;
    while (!q.empty())
    {
        int n = q.size();
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left && visited[node->left] == false)
            {
                q.push(node->left);
                visited[node->left] = true;
                flag = true;
            }
            if (node->right && visited[node->right] == false)
            {
                q.push(node->right);
                visited[node->right] = true;
                flag = true;
            }
            if (parents[node] && visited[parents[node]] == false)
            {
                q.push(parents[node]);
                visited[parents[node]] = true;
                flag = true;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    cout << minimum_time_required_to_burn(root, 2) << endl;
    return 0;
}