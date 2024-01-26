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

void preorder_inorder_postorder(Node *root)
{
    // Time: O(n)
    // Space: O(n)
    if (!root)
    {
        return;
    }
    vector<int> pre, in, post;
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        pair<Node *, int> curr = st.top();
        st.pop();
        if (curr.second == 1)
        {
            pre.push_back(curr.first->data);
            curr.second++;
            st.push(curr);
            if (curr.first->left)
            {
                st.push({curr.first->left, 1});
            }
        }
        else if (curr.second == 2)
        {
            in.push_back(curr.first->data);
            curr.second++;
            st.push(curr);
            if (curr.first->right)
            {
                st.push({curr.first->right, 1});
            }
        }
        else
        {
            post.push_back(curr.first->data);
        }
    }
    cout << "Preorder: ";
    for (auto i : pre)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Inorder: ";
    for (auto i : in)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Postorder: ";
    for (auto i : post)
    {
        cout << i << " ";
    }
    cout << endl;
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
    preorder_inorder_postorder(root);
    return 0;
}