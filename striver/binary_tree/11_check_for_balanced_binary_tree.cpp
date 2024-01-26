#include <iostream>
#include <queue>
#include <stack>
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

int max_depth(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        return 0;
    }
    int left = max_depth(root->left);
    int right = max_depth(root->right);
    return max(left, right) + 1;
}

bool is_balanced(Node *root)
{
    // Time: O(n^2)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        return true;
    }
    int left = max_depth(root->left);
    int right = max_depth(root->right);
    if (abs(left - right) > 1)
    {
        return false;
    }
    bool left_balanced = is_balanced(root->left);
    if (left_balanced == false)
    {
        return false;
    }
    bool right_balanced = is_balanced(root->right);
    if (right_balanced == false)
    {
        return false;
    }
    return true;
}

pair<int, bool> solve_is_balanced_2(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        return {0, true};
    }
    pair<int, bool> left = solve_is_balanced_2(root->left);
    if (left.second == false)
    {
        return {0, false};
    }
    pair<int, bool> right = solve_is_balanced_2(root->right);
    if (right.second == false)
    {
        return {0, false};
    }
    if (abs(left.first - right.first) > 1)
    {
        return {0, false};
    }
    return {max(left.first, right.first) + 1, true};
}

bool is_balanced_2(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    return solve_is_balanced_2(root).second;
}

int solve_is_balanced_3(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        return 0;
    }
    int left = solve_is_balanced_3(root->left);
    if (left == -1)
    {
        return -1;
    }
    int right = solve_is_balanced_3(root->right);
    if (right == -1)
    {
        return -1;
    }
    if (abs(left - right) > 1)
    {
        return -1;
    }
    return max(left, right) + 1;
}

bool is_balanced_3(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    if (solve_is_balanced_3(root) == -1)
    {
        return false;
    }
    return true;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << is_balanced(root) << endl;
    cout << is_balanced_2(root) << endl;
    cout << is_balanced_3(root) << endl;
    return 0;
}