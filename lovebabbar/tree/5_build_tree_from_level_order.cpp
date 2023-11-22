#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// class Node
// {
//     // N-Array Tree
//     int data;
//     vector<Node *> children;
//     Node(int data)
//     {
//         this->data = data;
//     }
// };

class Node
{
    // Binary Tree
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter The Data For Node : ";
    cin >> data;
    if (data == -1)
    {
        return root;
    }
    root = new Node(data);
    cout << "Enter Data For Inserting In Left : " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter Data For Inserting In Right : " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void level_order_traversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        else
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void in_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order_traversal(root->left);
    cout << root->data << " ";
    in_order_traversal(root->right);
}

void in_order_using_stack(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

void pre_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void pre_order_using_stack(Node *root)
{
    stack<Node *> st;
    if (root)
    {
        st.push(root);
    }
    while (!st.empty())
    {
        Node *top = st.top();
        st.pop();
        cout << top->data << " ";
        if (top->right)
        {
            st.push(top->right);
        }
        if (top->left)
        {
            st.push(top->left);
        }
    }
    cout << endl;
}

void post_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout << root->data << " ";
}

void post_order_using_stack(Node *root)
{
    if (root == NULL)
    {
        cout << endl;
        return;
    }
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
        {
            s1.push(temp->left);
        }
        if (temp->right)
        {
            s1.push(temp->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

void post_order_using_two_stack(Node *root)
{
    if (root == NULL)
    {
        cout << endl;
        return;
    }
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
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
    cout << endl;
}

void build_from_level_order(Node *&root)
{
    queue<Node *> q;
    cout << "Enter Data For Root : ";
    int data;
    cin >> data;
    if (data == -1)
    {
        return;
    }
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter Left Node of " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout << "Enter Right Node of " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    build_from_level_order(root);
    level_order_traversal(root);
    return 0;
}