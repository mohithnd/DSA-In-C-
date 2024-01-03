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

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void level_order(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        res.push_back(temp);
    }
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void iterative_preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }
    }
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
    cout << "Preorder: ";
    iterative_preorder(root);
    cout << endl;
    return 0;
}