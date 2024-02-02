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

bool root_to_node(Node *root, int k, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->data);
    if (root->data == k)
    {
        return true;
    }
    bool left = root_to_node(root->left, k, ans);
    if (left)
    {
        return true;
    }
    bool right = root_to_node(root->right, k, ans);
    if (right)
    {
        return true;
    }
    ans.pop_back();
    return false;
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int> ans;
    bool flag = root_to_node(root, 7, ans);
    if (flag)
    {
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found" << endl;
    }
    return 0;
}