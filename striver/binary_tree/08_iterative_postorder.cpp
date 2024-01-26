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

void iterative_postorder_using_two_stacks(Node *root)
{
    // using two stacks
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    if (!root)
    {
        return;
    }
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left)
        {
            st1.push(curr->left);
        }
        if (curr->right)
        {
            st1.push(curr->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void iterative_postorder_using_single_stacks(Node *root)
{
    // using single stack
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    if (!root)
    {
        return;
    }
    stack<Node *> st;
    Node *curr = root;
    while (curr != nullptr || st.empty() == false)
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                curr = temp;
            }
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
    cout << "postorder: ";
    iterative_postorder_using_two_stacks(root);
    cout << endl;
    cout << "postorder: ";
    iterative_postorder_using_single_stacks(root);
    cout << endl;
    return 0;
}