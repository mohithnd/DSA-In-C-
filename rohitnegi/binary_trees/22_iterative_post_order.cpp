#include <iostream>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

void iterative_post_order(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tree Is Empty" << endl;
        return;
    }
    stack<Node *> st;
    stack<int> rev;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        rev.push(curr->data);
        if (curr->left)
        {
            st.push(curr->left);
        }
        if (curr->right)
        {
            st.push(curr->right);
        }
    }
    while (!rev.empty())
    {
        cout << rev.top() << " ";
        rev.pop();
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->left->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    iterative_post_order(root);
    return 0;
}