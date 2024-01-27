#include <iostream>
#include <queue>
#include <stack>
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

bool identical_or_not(Node *root1, Node *root2)
{
    // time O(min(n1, n2))
    // space O(min(h1, h2))
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    if (identical_or_not(root1->left, root2->left) == false)
    {
        return false;
    }
    if (identical_or_not(root1->right, root2->right) == false)
    {
        return false;
    }
    return true;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right = new Node(5);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);

    Node *root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->right->right = new Node(5);

    cout << identical_or_not(root1, root2) << endl;
    cout << identical_or_not(root1, root3) << endl;
    cout << identical_or_not(root2, root3) << endl;
    return 0;
}