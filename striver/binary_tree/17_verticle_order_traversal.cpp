#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
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

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void level_order(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        res.push_back(temp);
    }
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void iterative_preorder(Node *root)
{
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

void iterative_inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    stack<Node *> st;
    Node *curr = root;
    while (true)
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void iterative_postorder_using_two_stacks(Node *root)
{
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

void preorder_inorder_postorder(Node *root)
{
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

void solve_vericle_order_1(Node *root, int x, int y, map<int, map<int, multiset<int>>> &mp)
{
    if (root == nullptr)
    {
        return;
    }
    mp[x][y].insert(root->data);
    solve_vericle_order_1(root->left, x - 1, y + 1, mp);
    solve_vericle_order_1(root->right, x + 1, y + 1, mp);
}

void vericle_order_1(Node *root)
{
    vector<vector<int>> res;
    map<int, map<int, multiset<int>>> mp;
    solve_vericle_order_1(root, 0, 0, mp);
    for (auto i : mp)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                temp.push_back(k);
            }
        }
        res.push_back(temp);
    }
    for (auto i : res)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);

    vericle_order_1(root);
    return 0;
}