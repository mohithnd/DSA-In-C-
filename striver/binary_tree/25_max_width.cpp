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

int max_width(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int n = q.size();
        int level_min = q.front().second;
        int start, end;
        for (int i = 0; i < n; i++)
        {
            pair<Node *, int> p = q.front();
            q.pop();
            long long curr_ind = p.second - level_min;
            if (i == 0)
            {
                start = curr_ind;
            }
            if (i == n - 1)
            {
                end = curr_ind;
            }
            if (p.first->left)
            {
                q.push({p.first->left, curr_ind * 2 + 1});
            }
            if (p.first->right)
            {
                q.push({p.first->right, curr_ind * 2 + 2});
            }
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(3);

    cout << max_width(root) << endl;
    return 0;
}