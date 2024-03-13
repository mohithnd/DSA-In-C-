#include <iostream>
#include <queue>
#include <vector>
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

Node *insert_in_bst(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert_in_bst(root->left, data);
    }
    else
    {
        root->right = insert_in_bst(root->right, data);
    }
    return root;
}

void inorder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void common_nodes_1(Node *r1, Node *r2)
{
    vector<int> a;
    inorder(r1, a);
    vector<int> b;
    inorder(r2, b);
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << endl;
}

void common_nodes_2(Node *r1, Node *r2)
{
    stack<Node *> st1;
    stack<Node *> st2;
    while (r1)
    {
        st1.push(r1);
        r1 = r1->left;
    }
    while (r2)
    {
        st2.push(r2);
        r2 = r2->left;
    }
    while (!st1.empty() && !st2.empty())
    {
        if (st1.top()->data == st2.top()->data)
        {
            cout << st1.top()->data << " ";
            r1 = st1.top()->right;
            r2 = st2.top()->right;
            st1.pop();
            st2.pop();
        }
        else if (st1.top()->data < st2.top()->data)
        {
            r1 = st1.top()->right;
            st1.pop();
        }
        else
        {
            r2 = st2.top()->right;
            st2.pop();
        }
        while (r1)
        {
            st1.push(r1);
            r1 = r1->left;
        }
        while (r2)
        {
            st2.push(r2);
            r2 = r2->left;
        }
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {5, 1, 10, 0, 4, 7, 9};
    Node *root1 = nullptr;
    for (int i : arr1)
    {
        root1 = insert_in_bst(root1, i);
    }
    vector<int> arr2 = {10, 7, 20, 4, 9};
    Node *root2 = nullptr;
    for (int i : arr2)
    {
        root2 = insert_in_bst(root2, i);
    }
    common_nodes_1(root1, root2);
    common_nodes_2(root1, root2);
    return 0;
}