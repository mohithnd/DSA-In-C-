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

vector<int> right_view_1(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->data);
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }
    return ans;
}

void solver(Node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (ans.size() < level)
    {
        ans.push_back(root->data);
    }
    solver(root->right, level + 1, ans);
    solver(root->left, level + 1, ans);
}

vector<int> right_view_2(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    solver(root, 1, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(10);
    root->right->right->left = new Node(9);
    root->right->left->left = new Node(8);
    root->right->left->left->left = new Node(11);

    vector<int> ans = right_view_1(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ans2 = right_view_1(root);
    for (int i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}