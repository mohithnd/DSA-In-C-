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

void solve(Node *root, int &sum, int &k)
{
    if (root == nullptr)
    {
        return;
    }
    if (k == 0)
    {
        return;
    }
    solve(root->left, sum, k);
    if (k == 0)
    {
        return;
    }
    sum += root->data;
    k--;
    solve(root->right, sum, k);
}

int sum_of_k_smallest(Node *root, int k)
{
    int sum = 0;
    solve(root, sum, k);
    return sum;
}

int main()
{
    Node *root = new Node(20);
    root->right = new Node(22);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << sum_of_k_smallest(root, 3) << endl;
    return 0;
}