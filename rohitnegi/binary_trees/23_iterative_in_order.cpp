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

void iterative_in_order(Node *root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    stack<Node *> st;
    stack<int> visitCount;
    st.push(root);
    visitCount.push(0);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        int cnt = visitCount.top();
        visitCount.pop();
        if (cnt == 0)
        {
            if (curr->right)
            {
                st.push(curr->right);
                visitCount.push(0);
            }
            st.push(curr);
            visitCount.push(1);
            if (curr->left)
            {
                st.push(curr->left);
                visitCount.push(0);
            }
        }
        else if (cnt == 1)
        {
            cout << curr->data << " ";
        }
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

    iterative_in_order(root);
    return 0;
}