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

bool find_path(Node *root, int key, vector<Node *> &path)
{
    if (root == nullptr)
    {
        return false;
    }
    path.push_back(root);
    if (root->data == key)
    {
        return true;
    }
    bool left = find_path(root->left, key, path);
    if (left)
    {
        return true;
    }
    bool right = find_path(root->right, key, path);
    if (right)
    {
        return true;
    }
    path.pop_back();
    return false;
}

Node *lca_1(Node *root, int a, int b)
{
    // time complexity: O(n)
    // space complexity: O(n)
    // two traversals
    vector<Node *> path1, path2;
    find_path(root, a, path1);
    find_path(root, b, path2);
    int n = path1.size();
    int m = path2.size();
    int i = 0;
    int j = 0;
    Node *ans = NULL;
    while (i < n && j < m)
    {
        if (path1[i]->data == path2[j]->data)
        {
            ans = path1[i];
            i++;
            j++;
        }
        else
        {
            break;
        }
    }
    return ans;
}

Node *lca_2(Node *root, int a, int b)
{
    // time complexity: O(n)
    // space complexity: O(n)
    // single traversal
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == a || root->data == b)
    {
        return root;
    }
    Node *left = lca_2(root->left, a, b);
    Node *right = lca_2(root->right, a, b);
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    Node *ans = lca_1(root, 4, 7);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << "No LCA" << endl;
        ;
    }
    ans = lca_2(root, 4, 7);
    if (ans != NULL)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << "No LCA" << endl;
    }
    return 0;
}