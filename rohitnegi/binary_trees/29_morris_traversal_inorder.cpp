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

vector<int> morris_traversal_inorder(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        cout << "Tree Is Empty" << endl;
        return ans;
    }
    while (root)
    {
        if (root->left == nullptr)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }
            if (curr->right == nullptr)
            {
                curr->right = root;
                root = root->left;
            }
            else
            {
                curr->right = nullptr;
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->right->right = new Node(9);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    vector<int> ans = morris_traversal_inorder(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}