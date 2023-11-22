#include <iostream>
#include <queue>
#include <map>
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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (left_height > right_height)
    {
        return 1 + left_height;
    }
    return 1 + right_height;
}

void print_current_level(Node *root, int curr_level, int desired_level)
{
    if (root == NULL || curr_level > desired_level)
    {
        return;
    }
    if (curr_level == desired_level)
    {
        cout << root->data << " ";
    }
    print_current_level(root->left, curr_level + 1, desired_level);
    print_current_level(root->right, curr_level + 1, desired_level);
}

void level_order_traversal1(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        print_current_level(root, 1, i);
        cout << endl;
    }
}

void solve(Node *root, int level, map<int, vector<Node *>> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[level].push_back(root);
    solve(root->left, level + 1, m);
    solve(root->right, level + 1, m);
}

void level_order_traversal2(Node *root)
{
    map<int, vector<Node *>> m;
    solve(root, 1, m);
    for (auto i : m)
    {
        for (auto j : i.second)
        {
            cout << j->data << " ";
        }
        cout << endl;
    }
}

void level_order_traversal3(Node *root)
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

void solve2(Node *root, int level, vector<vector<Node *>> &v)
{
    if (root == NULL)
    {
        return;
    }
    if (v.size() < level)
    {
        v.push_back({});
    }
    v[level - 1].push_back(root);
    solve2(root->left, level + 1, v);
    solve2(root->right, level + 1, v);
}

void level_order_traversal4(Node *root)
{
    vector<vector<Node *>> v;
    solve2(root, 1, v);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j->data << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    level_order_traversal1(root);
    cout << endl;
    level_order_traversal2(root);
    cout << endl;
    level_order_traversal3(root);
    cout << endl;
    level_order_traversal4(root);
    return 0;
}