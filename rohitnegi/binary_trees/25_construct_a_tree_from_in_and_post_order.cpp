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

int find(vector<int> in, int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
        {
            return i;
        }
    }
    return -1;
}

Node *constructor(vector<int> in, vector<int> post, int start, int end, int index)
{
    if (start > end)
    {
        return nullptr;
    }
    Node *root = new Node(post[index]);
    int pos = find(in, post[index], start, end);
    root->right = constructor(in, post, pos + 1, end, index - 1);
    root->left = constructor(in, post, start, pos - 1, index - (end - pos) - 1);
    return root;
}

int main()
{
    vector<int> inorder = {4, 2, 6, 5, 7, 1, 10, 8, 9, 3};
    vector<int> postorder = {4, 6, 7, 5, 2, 10, 9, 8, 3, 1};
    Node *root = constructor(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    level_order(root);
    return 0;
}