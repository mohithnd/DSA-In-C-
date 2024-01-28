#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_map>
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

void bottom_view(Node *root)
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    vector<int> res;
    if (root == nullptr)
    {
        return;
    }
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();
        m[curr.second] = curr.first->data;
        if (curr.first->left)
        {
            q.push({curr.first->left, curr.second - 1});
        }
        if (curr.first->right)
        {
            q.push({curr.first->right, curr.second + 1});
        }
    }
    for (auto i : m)
    {
        res.push_back(i.second);
    }
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

void solve(Node *root, int hd, int level, map<int, pair<Node *, int>> &m)
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n) because of recursion stack
    if (root == nullptr)
    {
        return;
    }
    if (m.find(hd) == m.end() || level >= m[hd].second)
    {
        m[hd] = {root, level};
    }
    solve(root->left, hd - 1, level + 1, m);
    solve(root->right, hd + 1, level + 1, m);
}

void bottom_view_2(Node *root)
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    if (root == nullptr)
    {
        cout << endl;
        return;
    }
    vector<int> res;
    map<int, pair<Node *, int>> m;
    solve(root, 0, 0, m);
    for (auto i : m)
    {
        res.push_back(i.second.first->data);
    }
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

void bottom_view_3(Node *root)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    if (!root)
    {
        cout << endl;
        return;
    }
    int left_most = 0;
    int right_most = 0;
    unordered_map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();
        m[curr.second] = curr.first->data;
        left_most = min(left_most, curr.second);
        right_most = max(right_most, curr.second);
        if (curr.first->left)
        {
            q.push({curr.first->left, curr.second - 1});
        }
        if (curr.first->right)
        {
            q.push({curr.first->right, curr.second + 1});
        }
    }
    for (int i = left_most; i <= right_most; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    bottom_view(root);
    bottom_view_2(root);
    bottom_view_3(root);
    return 0;
}