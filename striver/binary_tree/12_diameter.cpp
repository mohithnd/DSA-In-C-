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

int height(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int diameter(Node *root)
{
    // Time: O(n^2)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int curr_dia = lh + rh;
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(curr_dia, max(ld, rd));
}

void solve_diameter_2(Node *root, int &height, int &diameter)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    if (root == nullptr)
    {
        height = 0;
        diameter = 0;
        return;
    }
    int lh = 0, ld = 0;
    solve_diameter_2(root->left, lh, ld);
    int rh = 0, rd = 0;
    solve_diameter_2(root->right, rh, rd);
    height = max(lh, rh) + 1;
    diameter = max(lh + rh, max(ld, rd));
}

int diameter_2(Node *root)
{
    // Time: O(n)
    // Space: O(n) because of recursion stack
    int height = 0;
    int diameter = 0;
    solve_diameter_2(root, height, diameter);
    return diameter;
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
    cout << diameter(root) << endl;
    cout << diameter_2(root) << endl;
    return 0;
}