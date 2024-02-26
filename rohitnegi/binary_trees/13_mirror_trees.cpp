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
            cout << q.front()->data << " ";
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        cout << endl;
    }
    cout << endl;
}

void mirror_1(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    swap(root->left, root->right);
    mirror_1(root->left);
    mirror_1(root->right);
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
    mirror_1(root);
    level_order(root);
    return 0;
}