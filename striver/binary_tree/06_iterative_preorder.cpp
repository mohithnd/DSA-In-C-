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

void iterative_preorder(Node *root)
{
    // TC: O(n)
    // SC: O(n)
    if (!root)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }
    }
}

void iterative_preorder_2(Node *root)
{
    // TC: O(n)
    // SC: O(n)
    if (!root)
    {
        return;
    }
    stack<Node *> st;
    Node *curr = root;
    while (!st.empty() || curr != nullptr)
    {
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            if (curr->right)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
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
    cout << "Preorder: ";
    iterative_preorder(root);
    cout << endl;
    cout << "Preorder: ";
    iterative_preorder_2(root);
    cout << endl;
    return 0;
}