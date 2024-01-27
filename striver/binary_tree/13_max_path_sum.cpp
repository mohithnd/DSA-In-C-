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

int max_path_sum_helper(Node *root, int &ans)
{
    // Time: O(n)
    // Space: O(h)
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
    // Time: O(n)
    // Space: O(h)
    int ans = INT_MIN;
    max_path_sum_helper(root, ans);
    cout << ans << endl;
}

void max_path_sum_2(Node *root)
{
    // Time: O(n)
    // Space: O(h)
    int ans = INT_MIN;
    stack<pair<Node *, int>> st;
    st.push({root, 0});
    while (!st.empty())
    {
        pair<Node *, int> curr = st.top();
        st.pop();
        if (curr.first == nullptr)
        {
            continue;
        }
        if (curr.second == 0)
        {
            st.push({curr.first, 1});
            st.push({curr.first->left, 0});
        }
        else if (curr.second == 1)
        {
            st.push({curr.first, 2});
            st.push({curr.first->right, 0});
        }
        else
        {
            int left = curr.first->left ? curr.first->left->data : 0;
            int right = curr.first->right ? curr.first->right->data : 0;
            ans = max(ans, curr.first->data + max(0, left) + max(0, right));
            curr.first->data += max(0, max(left, right));
        }
    }
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
    max_path_sum_2(root);
    return 0;
}