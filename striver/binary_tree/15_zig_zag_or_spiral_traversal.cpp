#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
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

void zig_zag_or_spiral_traversal(Node *root)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<vector<int>> res;
    if (root == nullptr)
    {
        cout << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        if (flag)
        {
            reverse(temp.begin(), temp.end());
        }
        flag = !flag;
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

int height(Node *root)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n) because of recursion stack
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

void print_current_level(Node *root, int level, bool left_to_right, int curr_level)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n) because of recursion stack
    if (root == nullptr)
    {
        return;
    }
    if (curr_level == level)
    {
        cout << root->data << " ";
    }
    else
    {
        if (left_to_right)
        {
            print_current_level(root->left, level, left_to_right, curr_level + 1);
            print_current_level(root->right, level, left_to_right, curr_level + 1);
        }
        else
        {
            print_current_level(root->right, level, left_to_right, curr_level + 1);
            print_current_level(root->left, level, left_to_right, curr_level + 1);
        }
    }
}

void zig_zag_or_spiral_traversal_recursive(Node *root)
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n) because of recursion stack
    int h = height(root);
    bool left_to_right = true;
    for (int i = 1; i <= h; i++)
    {
        print_current_level(root, i, left_to_right, 1);
        cout << endl;
        left_to_right = !left_to_right;
    }
    cout << endl;
}

void zig_zag_or_spiral_traversal_deque(Node *root)
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    if (root == nullptr)
    {
        cout << endl;
        return;
    }
    deque<Node *> dq;
    dq.push_back(root);
    bool left_to_right = true;
    while (!dq.empty())
    {
        int n = dq.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr;
            if (left_to_right)
            {
                curr = dq.front();
                dq.pop_front();
            }
            else
            {
                curr = dq.back();
                dq.pop_back();
            }
            cout << curr->data << " ";
            if (left_to_right)
            {
                if (curr->left)
                {
                    dq.push_back(curr->left);
                }
                if (curr->right)
                {
                    dq.push_back(curr->right);
                }
            }
            else
            {
                if (curr->right)
                {
                    dq.push_front(curr->right);
                }
                if (curr->left)
                {
                    dq.push_front(curr->left);
                }
            }
        }
        left_to_right = !left_to_right;
        cout << endl;
    }
    cout << endl;
}

void zig_zag_or_spiral_traversal_stacks(Node *root)
{
    if (root == nullptr)
    {
        cout << endl;
        return;
    }
    bool left_to_right = true;
    stack<Node *> curr_level;
    stack<Node *> next_level;
    curr_level.push(root);
    while (!curr_level.empty())
    {
        Node *curr = curr_level.top();
        curr_level.pop();
        cout << curr->data << " ";
        if (left_to_right)
        {
            if (curr->left)
            {
                next_level.push(curr->left);
            }
            if (curr->right)
            {
                next_level.push(curr->right);
            }
        }
        else
        {
            if (curr->right)
            {
                next_level.push(curr->right);
            }
            if (curr->left)
            {
                next_level.push(curr->left);
            }
        }
        if (curr_level.empty())
        {
            left_to_right = !left_to_right;
            swap(curr_level, next_level);
            cout << endl;
        }
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
    root->right->right = new Node(6);

    zig_zag_or_spiral_traversal(root);
    cout << endl;
    zig_zag_or_spiral_traversal_recursive(root);
    zig_zag_or_spiral_traversal_deque(root);
    zig_zag_or_spiral_traversal_stacks(root);
    return 0;
}