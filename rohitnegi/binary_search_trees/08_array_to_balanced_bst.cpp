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

Node *create_balanced_bst(Node *root, vector<int> arr, int s, int e, vector<int> &pre)
{
    if (s > e)
    {
        return nullptr;
    }
    int mid = s + (e - s) / 2;
    root = new Node(arr[mid]);
    pre.push_back(root->data);
    root->left = create_balanced_bst(root->left, arr, s, mid - 1, pre);
    root->right = create_balanced_bst(root->right, arr, mid + 1, e, pre);
    return root;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *root = nullptr;
    vector<int> pre;
    root = create_balanced_bst(root, arr, 0, arr.size() - 1, pre);
    for (int i : pre)
    {
        cout << i << " ";
    }
    return 0;
}