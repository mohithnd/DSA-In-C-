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

void top_view(Node *root)
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    vector<int> res;
    if (!root)
    {
        return;
    }
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();
        int x = curr.second;
        if (mp.find(x) == mp.end())
        {
            mp[x] = curr.first->data;
        }
        if (curr.first->left)
        {
            q.push({curr.first->left, x - 1});
        }
        if (curr.first->right)
        {
            q.push({curr.first->right, x + 1});
        }
    }
    for (auto i : mp)
    {
        res.push_back(i.second);
    }
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

void top_view_2(Node *root)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    if (!root)
    {
        return;
    }
    queue<pair<Node *, int>> q;
    vector<int> right;
    stack<int> left;
    int hd = 0;
    int l = 0;
    int r = 0;
    q.push({root, hd});
    while (!q.empty())
    {
        pair<Node *, int> curr = q.front();
        q.pop();
        hd = curr.second;
        if (hd < l)
        {
            left.push(curr.first->data);
            l = hd;
        }
        else if (hd > r)
        {
            right.push_back(curr.first->data);
            r = hd;
        }
        if (curr.first->left)
        {
            q.push({curr.first->left, hd - 1});
        }
        if (curr.first->right)
        {
            q.push({curr.first->right, hd + 1});
        }
    }
    while (!left.empty())
    {
        cout << left.top() << " ";
        left.pop();
    }
    cout << root->data << " ";
    for (auto i : right)
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
    if (m.find(hd) == m.end() || m[hd].second > level)
    {
        m[hd] = {root, level};
    }
    solve(root->left, hd - 1, level + 1, m);
    solve(root->right, hd + 1, level + 1, m);
}

void top_view_3(Node *root)
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    vector<int> res;
    if (!root)
    {
        cout << endl;
        return;
    }
    map<int, pair<Node *, int>> m;
    solve(root, 0, 0, m);
    for (auto i : m)
    {
        res.push_back(i.second.first->data);
    }
    for (auto i : res)
    {
        cout << i << " ";
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
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);
    top_view(root);
    top_view_2(root);
    top_view_3(root);
    return 0;
}