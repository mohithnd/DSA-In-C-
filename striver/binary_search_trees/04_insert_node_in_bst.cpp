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
    if (root == nullptr)
    {
        cout << endl;
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

Node *insert_in_bst(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    Node *curr = root;
    while (true)
    {
        if (value > curr->data)
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(value);
                break;
            }
        }
        else
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(value);
                break;
            }
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(7);
    level_order(root);

    root = insert_in_bst(root, 5);
    level_order(root);

    return 0;
}