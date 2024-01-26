#include <iostream>
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
        this->left = this->right = NULL;
    }
};

void level_order(Node *root)
{
    // TC: O(n)
    // SC: O(n)
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

int height(Node *root)
{
    // TC: O(n)
    // SC: O(h) because of recursion stack
    if (!root)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

void print_current_level(Node *root, int level, int curr)
{
    // TC: O(n)
    // SC: O(h) because of recursion stack
    if (root == nullptr)
    {
        return;
    }
    if (level == curr)
    {
        cout << root->data << " ";
    }
    print_current_level(root->left, level, curr + 1);
    print_current_level(root->right, level, curr + 1);
}

void level_order_2(Node *root)
{
    // TC: O(n^2)
    // SC: O(h) because of recursion stack
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        print_current_level(root, i, 1);
        cout << endl;
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
    level_order(root);
    cout << endl;
    level_order_2(root);
    cout << endl;
    return 0;
}