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

void solve_left_view(Node *root, vector<int> &res, int level)
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
    solve_left_view(root->left, res, level + 1);
    solve_left_view(root->right, res, level + 1);
}

void left_view(Node *root)
{
    // time complexity: O(n)
    // space complexity: O(n) (for recursive stack)
    vector<int> res;
    solve_left_view(root, res, 0);
    for (auto i : res)
    {
        cout << i << " ";
    }
}

void left_view_iterative(Node *root)
{
    // time complexity: O(n)
    // space complexity: O(n)
    if (!root)
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
            if (i == 0)
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

void left_view_iterative_2(Node *root)
{
    // time complexity: O(n)
    // space complexity: O(n)
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool print = true;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (q.size() > 0)
            {
                q.push(NULL);
                print = true;
            }
        }
        else
        {
            if (print)
            {
                cout << curr->data << " ";
                print = false;
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
    cout << "Left View: " << endl;
    left_view(root);
    cout << endl;
    left_view_iterative(root);
    cout << endl;
    left_view_iterative_2(root);
    cout << endl;
    return 0;
}