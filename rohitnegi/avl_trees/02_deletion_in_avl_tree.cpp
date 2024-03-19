#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

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

            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
    cout << endl;
}

int get_height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->height;
}

int get_balance(Node *root)
{
    return get_height(root->left) - get_height(root->right);
}

Node *right_rotate(Node *root)
{
    Node *child = root->left;
    Node *child_right = child->right;
    child->right = root;
    root->left = child_right;
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));
    return child;
}

Node *left_rotate(Node *root)
{
    Node *child = root->right;
    Node *child_left = child->left;
    child->left = root;
    root->right = child_left;
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));
    return child;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int balance = get_balance(root);
    if (balance > 1 && data < root->left->data)
    {
        // Left Left
        return right_rotate(root);
    }
    else if (balance > 1 && data > root->left->data)
    {
        // Left Right
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    else if (balance < -1 && data > root->right->data)
    {
        // Right Right
        return left_rotate(root);
    }
    else if (balance < -1 && data < root->right->data)
    {
        // Right Left
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    else
    {
        return root;
    }
}

Node *delete_node(Node *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (data < root->data)
    {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_node(root->right, data);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == nullptr && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = delete_node(root->right, curr->data);
        }
    }
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int balance = get_balance(root);
    if (balance > 1)
    {
        if (get_balance(root->left) >= 0)
        {
            // Left Left
            return right_rotate(root);
        }
        else
        {
            // Left Right
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }
    else if (balance < -1)
    {
        if (get_balance(root->right) <= 0)
        {
            // Right Right
            return left_rotate(root);
        }
        else
        {
            // Right Left
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }
    else
    {
        return root;
    }
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);
    level_order(root);
    inorder(root);
    cout << endl;
    root = delete_node(root, 10);
    level_order(root);
    inorder(root);
    return 0;
}