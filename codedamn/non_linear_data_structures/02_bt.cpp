#include <iostream>
#include <vector>
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

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        this->root = nullptr;
    }

    void preorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void preorder()
    {
        preorder(this->root);
    }

    void inorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void inorder()
    {
        inorder(this->root);
    }

    void postorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void postorder()
    {
        postorder(this->root);
    }

    int height(Node *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }

    int height()
    {
        return height(this->root);
    }

    bool equal(Node *root1, Node *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }
        if (root1->data != root2->data)
        {
            return false;
        }
        if (equal(root1->left, root2->left) == false)
        {
            return false;
        }
        if (equal(root1->right, root2->right) == false)
        {
            return false;
        }
        return true;
    }

    bool equal(BinaryTree tree)
    {
        return equal(this->root, tree.root);
    }

    void nodes_at_k_distance_from_root(Node *root, int k, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (k == 0)
        {
            ans.push_back(root->data);
            return;
        }
        nodes_at_k_distance_from_root(root->left, k - 1, ans);
        nodes_at_k_distance_from_root(root->right, k - 1, ans);
    }

    vector<int> nodes_at_k_distance_from_root(int k)
    {
        vector<int> ans;
        nodes_at_k_distance_from_root(this->root, k, ans);
        return ans;
    }

    vector<vector<int>> level_order()
    {
        vector<vector<int>> ans;
        Node *curr = this->root;
        queue<Node *> q;
        q.push(curr);
        while (!q.empty())
        {
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                q.pop();
                v.push_back(temp->data);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }

    pair<int, int> diameter(Node *root)
    {
        if (root == nullptr)
        {
            return make_pair(0, 0);
        }
        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);
        int ld = left.first;
        int rd = right.first;
        int lh = left.second;
        int rh = right.second;
        int d = max(max(ld, rd), 1 + lh + rh);
        int h = 1 + max(lh, rh);
        return make_pair(d, h);
    }

    int diameter()
    {
        pair<int, int> ans = diameter(this->root);
        return ans.first;
    }

    pair<bool, int> balanced(Node *root)
    {
        if (root == nullptr)
        {
            return make_pair(true, 0);
        }
        pair<bool, int> left = balanced(root->left);
        if (left.first == false)
        {
            return make_pair(false, 0);
        }
        pair<bool, int> right = balanced(root->right);
        if (right.first == false)
        {
            return make_pair(false, 0);
        }
        int diff = abs(left.second - right.second);
        if (diff > 1)
        {
            return make_pair(false, 0);
        }
        int h = 1 + max(left.first, right.first);
        return make_pair(true, h);
    }

    bool balanced()
    {
        return balanced(this->root).first;
    }

    pair<bool, int> sum_tree(Node *root)
    {
        if (root == nullptr)
        {
            return make_pair(true, 0);
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return make_pair(true, root->data);
        }
        pair<bool, int> left = sum_tree(root->left);
        if (left.first == false)
        {
            return make_pair(false, 0);
        }
        pair<bool, int> right = sum_tree(root->right);
        if (right.first == false)
        {
            return make_pair(false, 0);
        }
        if (root->data != (left.second + right.second))
        {
            return make_pair(false, 0);
        }
        return make_pair(true, 2 * root->data);
    }

    bool sum_tree()
    {
        return sum_tree(this->root).first;
    }

    vector<vector<int>> zig_zag()
    {
        vector<vector<int>> ans;
        bool left_to_right = true;
        queue<Node *> q;
        Node *curr = this->root;
        q.push(curr);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (left_to_right)
                {
                    v.push_back(temp->data);
                }
                else
                {
                    v.insert(v.begin(), temp->data);
                }
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
            left_to_right = !left_to_right;
        }
        return ans;
    }
};

int main()
{
    BinaryTree tree = BinaryTree();
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);
    for (auto i : tree.level_order())
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    for (auto i : tree.zig_zag())
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}