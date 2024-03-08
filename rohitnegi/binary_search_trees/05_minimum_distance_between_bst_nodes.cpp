#include <iostream>
#include <queue>
#include <vector>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

int solve(Node *root, int &last)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }
    int left = solve(root->left, last);
    int curr = INT_MAX;
    if (last != INT_MIN)
    {
        curr = abs(root->data - last);
    }
    last = root->data;
    int right = solve(root->right, last);
    return min(curr, min(left, right));
}

int minimum_distance(Node *root)
{
    int last = INT_MIN;
    return solve(root, last);
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(14);
    root->right = new Node(30);
    root->right->left = new Node(25);
    root->right->right = new Node(35);
    cout << minimum_distance(root) << endl;
    return 0;
}