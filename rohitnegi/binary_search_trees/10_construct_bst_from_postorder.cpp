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

Node *create_1(vector<int> postorder, int s, int e)
{
    if (s > e)
    {
        return nullptr;
    }
    Node *root = new Node(postorder[e]);
    int prev_small = -1;
    for (int i = e - 1; i >= s; i--)
    {
        if (postorder[i] < postorder[e])
        {
            prev_small = i;
            break;
        }
    }
    if (prev_small != -1)
    {
        root->left = create_1(postorder, s, prev_small);
        root->right = create_1(postorder, prev_small + 1, e - 1);
    }
    else
    {
        root->right = create_1(postorder, s, e - 1);
    }
    return root;
}

Node *create_2(vector<int> postorder, int &i, int lower, int higher)
{
    if (i < 0)
    {
        return nullptr;
    }
    if (postorder[i] > lower && postorder[i] < higher)
    {
        Node *root = new Node(postorder[i]);
        i--;
        root->right = create_2(postorder, i, root->data, higher);
        i--;
        root->left = create_2(postorder, i, lower, root->data);
        return root;
    }
    i++;
    return nullptr;
}

int main()
{
    vector<int> postorder = {1, 7, 5, 50, 40, 10};
    Node *root = nullptr;
    // root = create_1(postorder, 0, postorder.size() - 1);
    int i = postorder.size() - 1;
    root = create_2(postorder, i, INT_MIN, INT_MAX);
    inorder(root);
    return 0;
}