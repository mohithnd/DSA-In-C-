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

void flatten(Node *root)
{
    while (root)
    {
        if (root->left == nullptr)
        {
            root = root->right;
        }
        else
        {
            Node *curr = root->left;
            while (curr->right)
            {
                curr = curr->right;
            }
            curr->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->left->left->right = new Node(4);
    root->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    flatten(root);
    while (root)
    {
        cout << root->data << " ";
        if (root->left)
        {
            cout << " - Failed - ";
        }
        root = root->right;
    }
    return 0;
}