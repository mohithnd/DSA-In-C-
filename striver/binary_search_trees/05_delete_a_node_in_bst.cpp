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

Node *find_right(Node *root)
{
    if (root->right == nullptr)
    {
        return root;
    }
    return find_right(root->right);
}

Node *delete_a_node_helper(Node *root)
{
    if (root->left == nullptr)
    {
        return root->right;
    }
    if (root->right == nullptr)
    {
        return root->left;
    }
    Node *right_child = root->right;
    Node *last_right_of_left = find_right(root->left);
    last_right_of_left->right = right_child;
    return root->left;
}

Node *delete_a_node(Node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == val)
    {
        return delete_a_node_helper(root);
    }
    Node *curr = root;
    while (root)
    {
        if (val < root->data)
        {
            if (root->left != nullptr && root->left->data == val)
            {
                root->left = delete_a_node_helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right && root->right->data == val)
            {
                root->right = delete_a_node_helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return curr;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(6);
    root->right->right = new Node(6);
    level_order(root);

    root = delete_a_node(root, 3);
    level_order(root);
    return 0;
}