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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    Node *root = new Node(10);
    root->left = new Node(12);
    root->left->left = new Node(8);
    root->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
    return root;
}

int method1(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + method1(root->left) + method1(root->right);
}

int method2(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        ans++;
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return ans;
}

int main()
{
    Node *root = createTree();
    cout << method1(root) << endl;
    cout << method2(root) << endl;
    return 0;
}