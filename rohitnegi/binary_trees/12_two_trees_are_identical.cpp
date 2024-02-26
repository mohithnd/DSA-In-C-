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
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool identical_1(Node *r1, Node *r2)
{
    if (r1 == nullptr && r1 == nullptr)
    {
        return true;
    }
    if (r1 == nullptr || r1 == nullptr)
    {
        return false;
    }
    if (r1->data != r2->data)
    {
        return false;
    }
    if (identical_1(r1->left, r2->left) == false)
    {
        return false;
    }
    if (identical_1(r1->right, r2->right) == false)
    {
        return false;
    }
    return true;
}

int main()
{
    Node *r1 = new Node(1);
    r1->left = new Node(2);
    r1->left->left = new Node(4);
    r1->left->right = new Node(5);
    r1->right = new Node(3);
    r1->right->right = new Node(6);
    r1->right->right->right = new Node(7);

    Node *r2 = new Node(1);
    r2->left = new Node(2);
    r2->left->left = new Node(4);
    r2->left->right = new Node(5);
    r2->right = new Node(3);
    r2->right->right = new Node(6);
    r2->right->right->right = new Node(7);

    cout << identical_1(r1, r2) << endl;
    return 0;
}