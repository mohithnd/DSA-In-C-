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

void vertical_order_1(Node *root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    vector<vector<int>> pos;
    vector<vector<int>> neg;
    queue<Node *> q;
    queue<int> ind;
    q.push(root);
    ind.push(0);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int i = ind.front();
        ind.pop();
        if (i >= 0)
        {
            if (i >= pos.size())
            {
                vector<int> temp = {curr->data};
                pos.push_back(temp);
            }
            else
            {
                pos[i].push_back(curr->data);
            }
        }
        else
        {
            int i2 = -i;
            i2--;
            if (i2 >= neg.size())
            {
                vector<int> temp = {curr->data};
                neg.push_back(temp);
            }
            else
            {
                neg[i2].push_back(curr->data);
            }
        }
        if (curr->left)
        {
            q.push(curr->left);
            ind.push(i - 1);
        }
        if (curr->right)
        {
            q.push(curr->right);
            ind.push(i + 1);
        }
    }
    for (int i = neg.size() - 1; i >= 0; i--)
    {
        for (int j : neg[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    for (vector<int> v : pos)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->left->left->right->left = new Node(11);
    root->left->left->right->right = new Node(12);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    root->right->right->right->left = new Node(13);
    vertical_order_1(root);
    return 0;
}