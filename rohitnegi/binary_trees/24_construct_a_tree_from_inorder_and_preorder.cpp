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

void level_order(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tree Is Empty" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
    cout << endl;
}

int find(vector<int> inorder, int ele, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (inorder[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

Node *constructor(vector<int> inorder, vector<int> preorder, int instart, int inend, int index)
{
    if (instart > inend)
    {
        return nullptr;
    }
    Node *root = new Node(preorder[index]);
    int pos = find(inorder, preorder[index], instart, inend);
    root->left = constructor(inorder, preorder, instart, pos - 1, index + 1);
    root->right = constructor(inorder, preorder, pos + 1, inend, index + (pos - instart + 1));
    return root;
}

int main()
{
    vector<int> inorder = {4, 2, 8, 5, 9, 1, 6, 3, 7, 10};
    vector<int> preorder = {1, 2, 4, 5, 8, 9, 3, 6, 7, 10};
    Node *root = constructor(inorder, preorder, 0, inorder.size() - 1, 0);
    level_order(root);
    return 0;
}