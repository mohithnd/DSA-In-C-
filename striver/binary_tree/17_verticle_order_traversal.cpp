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

void solve_vericle_order_1(Node *root, int x, int y, map<int, map<int, multiset<int>>> &mp)
{
    // time complexity:- O(nlogn)
    // space complexity:- O(n) because of recursion stack
    if (root == nullptr)
    {
        return;
    }
    mp[x][y].insert(root->data);
    solve_vericle_order_1(root->left, x - 1, y + 1, mp);
    solve_vericle_order_1(root->right, x + 1, y + 1, mp);
}

void vericle_order_1(Node *root)
{
    // time complexity:- O(nlogn)
    // space complexity:- O(n) because of recursion map and recursion stack
    vector<vector<int>> res;
    map<int, map<int, multiset<int>>> mp;
    solve_vericle_order_1(root, 0, 0, mp);
    for (auto i : mp)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                temp.push_back(k);
            }
        }
        res.push_back(temp);
    }
    for (auto i : res)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void vericle_order_2(Node *root)
{
    // time complexity:- O(nlogn)
    // space complexity:- O(n)
    vector<vector<int>> res;
    map<int, map<int, multiset<int>>> mp;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        mp[x][y].insert(temp->data);
        if (temp->left)
        {
            q.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            q.push({temp->right, {x + 1, y + 1}});
        }
    }
    for (auto i : mp)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                temp.push_back(k);
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

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);

    vericle_order_1(root);
    cout << endl;
    vericle_order_2(root);
    return 0;
}