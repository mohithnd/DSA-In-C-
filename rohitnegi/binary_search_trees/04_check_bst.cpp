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

bool inorder_1(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return true;
    }
    if (inorder_1(root->left, arr) == false)
    {
        return false;
    }
    if (arr.size() != 0 && arr[arr.size() - 1] >= root->data)
    {
        return false;
    }
    arr.push_back(root->data);
    return inorder_1(root->right, arr);
}

bool check_1(Node *root)
{
    vector<int> arr;
    return inorder_1(root, arr);
}

bool inorder_2(Node *root, int &last)
{
    if (root == nullptr)
    {
        return true;
    }
    if (inorder_2(root->left, last) == false)
    {
        return false;
    }
    if (last != -1 && last >= root->data)
    {
        return false;
    }
    last = root->data;
    return inorder_2(root->right, last);
}

bool check_2(Node *root)
{
    int last = -1;
    return inorder_2(root, last);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(25);
    cout << check_1(root) << endl;
    cout << check_2(root) << endl;
    root->left->right->right->data = 19;
    cout << check_1(root) << endl;
    cout << check_2(root) << endl;
    return 0;
}