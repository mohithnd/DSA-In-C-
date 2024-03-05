#include <iostream>
#include <vector>
#include <queue>
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

void solve(Node *root, int ind, vector<vector<int>> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (ind >= ans.size())
    {
        vector<int> temp = {root->data};
        ans.push_back(temp);
    }
    else
    {
        ans[ind].push_back(root->data);
    }
    solve(root->left, ind + 1, ans);
    solve(root->right, ind, ans);
}

void diagonal_1(Node *root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    vector<vector<int>> ans;
    solve(root, 0, ans);
    for (auto i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    diagonal_1(root);
    return 0;
}