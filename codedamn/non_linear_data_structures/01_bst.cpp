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

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    Node *insert(Node *root, int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }

    void insert(int data)
    {
        this->root = insert(this->root, data);
    }

    bool find(Node *root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (data < root->data)
        {
            return find(root->left, data);
        }
        return find(root->right, data);
    }

    bool find(int data)
    {
        return find(this->root, data);
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

    int depth(Node *root, int d, int data)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (data == root->data)
        {
            return d;
        }
        if (data < root->data)
        {
            return depth(root->left, d + 1, data);
        }
        return depth(root->right, d + 1, data);
    }

    int depth(int data)
    {
        return depth(this->root, 0, data);
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

    int heightForNode(Node *root, int data)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (data == root->data)
        {
            return height(root);
        }
        if (data < root->data)
        {
            return heightForNode(root->left, data);
        }
        return heightForNode(root->right, data);
    }

    int heightForNode(int data)
    {
        return heightForNode(this->root, data);
    }

    int min(Node *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (root->left == nullptr)
        {
            return root->data;
        }
        return min(root->left);
    }

    int min()
    {
        return min(this->root);
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

    bool equal(BinarySearchTree tree)
    {
        return equal(this->root, tree.root);
    }

    bool validate(Node *root, long long lower, long long upper)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->data <= lower || root->data >= upper)
        {
            return false;
        }
        if (validate(root->left, lower, root->data) == false)
        {
            return false;
        }
        return validate(root->right, root->data, upper);
    }

    bool validate(BinarySearchTree tree)
    {
        return validate(tree.root, LONG_LONG_MIN, LONG_LONG_MAX);
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
};

int main()
{
    BinarySearchTree tree = BinarySearchTree();
    int arr[] = {7, 3, 4, 8, 10, 2};
    for (int i : arr)
    {
        tree.insert(i);
    }
    vector<vector<int>> ans = tree.level_order();
    for (vector<int> v : ans)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}