#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
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

    void add_left(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return;
        }
        ans.push_back(root->data);
        if (root->left)
        {
            add_left(root->left, ans);
        }
        else
        {
            add_left(root->right, ans);
        }
    }

    void add_leaves(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->data);
            return;
        }
        add_leaves(root->left, ans);
        add_leaves(root->right, ans);
    }

    void add_right(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return;
        }
        if (root->right)
        {
            add_right(root->right, ans);
        }
        else
        {
            add_right(root->left, ans);
        }
        ans.push_back(root->data);
    }

    vector<int> boundary()
    {
        vector<int> ans;
        if (this->root == nullptr)
        {
            return ans;
        }
        ans.push_back(root->data);
        add_left(root->left, ans);
        add_leaves(root->left, ans);
        add_leaves(root->right, ans);
        add_right(root->right, ans);
        return ans;
    }

    vector<int> verticle_order()
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        map<int, vector<int>> m;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *curr = q.front().first;
            int x = q.front().second;
            m[x].push_back(curr->data);
            q.pop();
            if (curr->left)
            {
                q.push({curr->left, x - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, x + 1});
            }
        }
        for (auto line : m)
        {
            for (int i : line.second)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> top_view()
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        map<int, int> m;
        while (!q.empty())
        {
            Node *curr = q.front().first;
            int x = q.front().second;
            q.pop();
            if (m.find(x) == m.end())
            {
                m[x] = curr->data;
            }
            if (curr->left)
            {
                q.push({curr->left, x - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, x + 1});
            }
        }
        for (auto i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

    vector<int> bottom_view()
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        map<int, int> m;
        while (!q.empty())
        {
            Node *curr = q.front().first;
            int x = q.front().second;
            q.pop();
            m[x] = curr->data;
            if (curr->left)
            {
                q.push({curr->left, x - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, x + 1});
            }
        }
        for (auto i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

    vector<int> right_view()
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
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
                if (i == n - 1)
                {
                    ans.push_back(curr->data);
                }
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }

    vector<int> left_view()
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
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
                if (i == 0)
                {
                    ans.push_back(curr->data);
                }
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }

    vector<int> diagonal_traversal()
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            while (curr)
            {
                ans.push_back(curr->data);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                curr = curr->right;
            }
        }
        return ans;
    }

    pair<int, int> sum_of_longest_bloodline(Node *root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }
        pair<int, int> left = sum_of_longest_bloodline(root->left);
        pair<int, int> right = sum_of_longest_bloodline(root->right);
        if (left.first > right.first)
        {
            return {left.first + 1, left.second + root->data};
        }
        else if (right.first > left.first)
        {
            return {right.first + 1, right.second + root->data};
        }
        else if (left.second > right.second)
        {
            return {left.first + 1, left.second + root->data};
        }
        else
        {
            return {right.first + 1, right.second + root->data};
        }
    }

    int sum_of_longest_bloodline()
    {
        return sum_of_longest_bloodline(root).second;
    }

    int lca(Node *root, int a, int b)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (root->data == a || root->data == b)
        {
            return root->data;
        }
        int left = lca(root->left, a, b);
        int right = lca(root->right, a, b);
        if (left != -1 && right != -1)
        {
            return root->data;
        }
        if (left == -1)
        {
            return right;
        }
        return left;
    }

    int lca(int a, int b)
    {
        return lca(root, a, b);
    }

    Node *find_node_and_map_parent(Node *root, unordered_map<Node *, Node *> &parent, int target)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        parent[root->left] = root;
        parent[root->right] = root;
        Node *left = find_node_and_map_parent(root->left, parent, target);
        Node *right = find_node_and_map_parent(root->right, parent, target);
        if (root->data == target)
        {
            return root;
        }
        if (left)
        {
            return left;
        }
        return right;
    }

    int minimum_time_to_burn(int target)
    {
        int ans = -1;
        if (root == nullptr)
        {
            return ans;
        }
        unordered_map<Node *, Node *> parent;
        Node *target_node = find_node_and_map_parent(root, parent, target);
        unordered_map<Node *, bool> visited;
        queue<Node *> q;
        q.push(target_node);
        visited[target_node] = true;
        while (!q.empty())
        {
            ans++;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        return ans;
    }

    vector<int> morris_traversal()
    {
        vector<int> ans;
        Node *curr = this->root;
        while (curr)
        {
            if (curr->left == nullptr)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *last = curr->left;
                while (last->right && last->right != curr)
                {
                    last = last->right;
                }
                if (last->right == nullptr)
                {
                    last->right = curr;
                    curr = curr->left;
                }
                else
                {
                    last->right = nullptr;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }

    void flatten_tree()
    {
        Node *curr = this->root;
        while (curr)
        {
            if (curr->left == nullptr)
            {
                curr = curr->right;
            }
            else
            {
                Node *last = curr->left;
                while (last->right)
                {
                    last = last->right;
                }
                last->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
        }
    }

    Node *merge(Node *r1, Node *r2)
    {
        if (r1 == nullptr)
        {
            return r2;
        }
        if (r2 == nullptr)
        {
            return r1;
        }
        Node *ans = new Node(r1->data + r2->data);
        ans->left = merge(r1->left, r2->left);
        ans->right = merge(r1->right, r2->right);
        return ans;
    }

    Node *merge(BinaryTree tree)
    {
        return merge(this->root, tree.root);
    }

    class Pair
    {
    public:
        int min;
        int max;
        bool is_valid_bst;
        int size;
        Pair()
        {
            this->min = INT_MAX;
            this->max = INT_MIN;
            this->is_valid_bst = true;
            this->size = 0;
        }
    };

    Pair size_of_largest_bst(Node *root, int &ans)
    {
        if (root == nullptr)
        {
            return Pair();
        }
        Pair left = size_of_largest_bst(root->left, ans);
        Pair right = size_of_largest_bst(root->right, ans);
        Pair curr = Pair();
        curr.min = min(root->data, left.min);
        curr.max = max(root->data, right.max);
        curr.size = left.size + right.size + 1;
        bool is_curr_valid = left.max < root->data && right.min > root->data;
        if (is_curr_valid && left.is_valid_bst && right.is_valid_bst)
        {
            curr.is_valid_bst = true;
            ans = max(ans, curr.size);
        }
        else
        {
            curr.is_valid_bst = false;
        }
        return curr;
    }

    int size_of_largest_bst()
    {
        int ans = 0;
        size_of_largest_bst(root, ans);
        return ans;
    }
};

int main()
{
    BinaryTree tree = BinaryTree();
    tree.root = new Node(5);
    tree.root->left = new Node(2);
    tree.root->right = new Node(4);
    tree.root->left->left = new Node(1);
    tree.root->left->right = new Node(3);
    cout << tree.size_of_largest_bst() << endl;
    return 0;
}