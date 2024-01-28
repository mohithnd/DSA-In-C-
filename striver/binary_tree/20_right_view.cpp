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

void solve_right_view(Node *root, vector<int> &res, int level)
{
    // time complexity: O(n)
    // space complexity: O(n) (for recursive stack)
    if (root == nullptr)
    {
        return;
    }
    if (res.size() == level)
    {
        res.push_back(root->data);
    }
    solve_right_view(root->right, res, level + 1);
    solve_right_view(root->left, res, level + 1);
}

void right_view(Node *root)
{
    // time complexity: O(n)
    // space complexity: O(n) (for recursive stack)
    vector<int> res;
    solve_right_view(root, res, 0);
    for (auto i : res)
    {
        cout << i << " ";
    }
}

void right_view_iterative(Node *root)
{
    // time complexity: O(n)
    // space complexity: O(n)
    if (root == nullptr)
    {
        return;
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
            if (i == n - 1)
            {
                cout << curr->data << " ";
            }
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
    cout << "Right View: " << endl;
    right_view(root);
    cout << endl;
    right_view_iterative(root);
    cout << endl;
    return 0;
}