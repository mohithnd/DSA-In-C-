#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class LinkedListNode
{
public:
    int data;
    LinkedListNode *next;
    LinkedListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void level_order(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "Tree Is Empty" << endl;
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
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
    cout << endl;
}

void ll_to_array(LinkedListNode *head, vector<int> &arr)
{
    while (head)
    {
        arr.push_back(head->data);
        head = head->next;
    }
}

TreeNode *array_to_balanced_bst(vector<int> &arr, int s, int e)
{
    if (s > e)
    {
        return nullptr;
    }
    int mid;
    if ((s + e) % 2 == 0)
    {
        mid = (s + e) / 2;
    }
    else
    {
        mid = (s + e) / 2 + 1;
    }
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = array_to_balanced_bst(arr, s, mid - 1);
    root->right = array_to_balanced_bst(arr, mid + 1, e);
    return root;
}

TreeNode *sorted_ll_to_bst(LinkedListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    vector<int> arr;
    ll_to_array(head, arr);
    return array_to_balanced_bst(arr, 0, arr.size() - 1);
}

int main()
{
    LinkedListNode *head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    head->next->next->next = new LinkedListNode(4);
    head->next->next->next->next = new LinkedListNode(5);
    head->next->next->next->next->next = new LinkedListNode(6);
    head->next->next->next->next->next->next = new LinkedListNode(7);

    TreeNode *root = sorted_ll_to_bst(head);
    level_order(root);
    return 0;
}