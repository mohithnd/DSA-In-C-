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

Node *create_tree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    Node *root = new Node(data);
    cout << "Enter Left Child of " << data << " : ";
    root->left = create_tree();
    cout << "Enter Right Child of " << data << " : ";
    root->right = create_tree();
    return root;
}

int main()
{
    // Create Tree using Recursion (Preorder Traversal)
    cout << "Enter Data For Root : ";
    Node *root = create_tree();
    return 0;
}