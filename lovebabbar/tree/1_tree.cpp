#include <iostream>
#include <queue>
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

void level_order_traversal(Node *root)
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

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    level_order_traversal(root);
    return 0;
}