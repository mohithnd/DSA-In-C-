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

int max_path_sum_helper(Node *root, int &ans)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = max_path_sum_helper(root->left, ans);
    int right = max_path_sum_helper(root->right, ans);
    int node_max = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, node_max);
    return max(root->data, max(root->data + left, root->data + right));
}

void max_path_sum(Node *root)
{
    int ans = INT_MIN;
    max_path_sum_helper(root, ans);
    cout << ans << endl;
}

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    max_path_sum(root);
    return 0;
}