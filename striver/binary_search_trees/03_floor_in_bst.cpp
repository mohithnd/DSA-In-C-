#include <iostream>
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

int floor_in_bst(Node *root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->data == key)
        {
            floor = root->data;
            break;
        }
        if (key > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    cout << floor_in_bst(root, 7) << endl;
    return 0;
}