#include <iostream>
#include <queue>
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

void level_order(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tree Is Empty" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
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
        cout << endl;
    }
}

void inorder(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void fill_using_post_order(Node *root, vector<int> &ans, int &i)
{
    if (root == nullptr)
    {
        return;
    }
    fill_using_post_order(root->left, ans, i);
    fill_using_post_order(root->right, ans, i);
    root->data = ans[i];
    i++;
}

void bst_to_max_heap_1(Node *root)
{
    vector<int> ans;
    inorder(root, ans);
    int i = 0;
    fill_using_post_order(root, ans, i);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    level_order(root);
    bst_to_max_heap_1(root);
    level_order(root);
    return 0;
}