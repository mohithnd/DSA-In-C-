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

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *create_1(vector<int> arr, int s, int e)
{
    if (s > e)
    {
        return nullptr;
    }
    Node *root = new Node(arr[s]);
    int next_bid_ind = -1;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] > arr[s])
        {
            next_bid_ind = i;
            break;
        }
    }
    if (next_bid_ind != -1)
    {
        root->left = create_1(arr, s + 1, next_bid_ind - 1);
        root->right = create_1(arr, next_bid_ind, e);
    }
    else
    {
        root->left = create_1(arr, s + 1, e);
    }
    return root;
}

Node *create_2(vector<int> preorder, int &i, int lower, int higher)
{
    if (i >= preorder.size())
    {
        return nullptr;
    }
    if (preorder[i] > lower && preorder[i] < higher)
    {
        Node *root = new Node(preorder[i]);
        i++;
        root->left = create_2(preorder, i, lower, root->data);
        i++;
        root->right = create_2(preorder, i, root->data, higher);
        return root;
    }
    i--;
    return nullptr;
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Node *root = nullptr;
    // root = create_1(preorder, 0, preorder.size() - 1);
    int i = 0;
    root = create_2(preorder, i, INT_MIN, INT_MAX);
    inorder(root);
    return 0;
}