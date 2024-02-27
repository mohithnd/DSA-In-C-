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

void find_left_and_right_most(Node *root, int ind, int &left, int &right)
{
    if (root == nullptr)
    {
        return;
    }
    left = min(left, ind);
    right = max(right, ind);
    find_left_and_right_most(root->left, ind - 1, left, right);
    find_left_and_right_most(root->right, ind + 1, left, right);
}

vector<int> top_view_1(Node *root)
{
    if (root == nullptr)
    {
        vector<int> ans;
        return ans;
    }
    int left_most = INT_MAX;
    int right_most = INT_MIN;
    find_left_and_right_most(root, 0, left_most, right_most);
    int distance = right_most - left_most + 1;
    queue<Node *> q;
    queue<int> index;
    vector<int> ans(distance, 0);
    vector<bool> filled(distance, false);
    q.push(root);
    index.push((-1) * left_most);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int pos = index.front();
        index.pop();
        if (filled[pos] == false)
        {
            filled[pos] = true;
            ans[pos] = curr->data;
        }
        if (curr->left)
        {
            q.push(curr->left);
            index.push(pos - 1);
        }
        if (curr->right)
        {
            q.push(curr->right);
            index.push(pos + 1);
        }
    }
    return ans;
}

void solve(Node *root, int pos, int vd, vector<int> &ans, vector<int> &level)
{
    if (root == nullptr)
    {
        return;
    }
    if (vd < level[pos])
    {
        level[pos] = vd;
        ans[pos] = root->data;
    }
    solve(root->left, pos - 1, vd + 1, ans, level);
    solve(root->right, pos + 1, vd + 1, ans, level);
}

vector<int> top_view_2(Node *root)
{
    if (root == nullptr)
    {
        vector<int> ans;
        return ans;
    }
    int left_most = INT_MAX;
    int right_most = INT_MIN;
    find_left_and_right_most(root, 0, left_most, right_most);
    int dis = right_most - left_most + 1;
    vector<int> ans(dis, 0);
    vector<int> level(dis, INT_MAX);
    solve(root, (-1) * left_most, 0, ans, level);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    root->right->right->right->left = new Node(13);
    root->right->right->left->left = new Node(12);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->left->left->right = new Node(8);
    root->left->left->left = new Node(7);
    root->left->left->left->left = new Node(11);

    vector<int> ans = top_view_1(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ans2 = top_view_2(root);
    for (int i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}