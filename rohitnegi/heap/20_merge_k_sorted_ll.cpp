#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void print(Node *ll)
{
    while (ll)
    {
        cout << ll->data << " ";
        ll = ll->next;
    }
    cout << endl;
}

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *merge_1(Node *lls[], int k)
{
    priority_queue<Node *, vector<Node *>, Compare> q;
    for (int i = 0; i < k; i++)
    {
        Node *curr = lls[i];
        while (curr)
        {
            q.push(curr);
            curr = curr->next;
        }
    }
    Node *head = new Node(-1);
    Node *tail = head;
    while (!q.empty())
    {
        Node *temp = q.top();
        q.pop();
        tail->next = temp;
        tail = tail->next;
    }
    tail->next = nullptr;
    return head->next;
}

Node *merge_2(Node *lls[], int k)
{
    priority_queue<Node *, vector<Node *>, Compare> q(lls, lls + k);
    Node *head = new Node(-1);
    Node *tail = head;
    while (!q.empty())
    {
        Node *temp = q.top();
        q.pop();
        if (temp->next)
        {
            q.push(temp->next);
        }
        tail->next = temp;
        tail = tail->next;
    }
    tail->next = nullptr;
    return head->next;
}

int main()
{
    Node *lls[6];
    lls[0] = new Node(4);
    lls[0]->next = new Node(7);
    lls[0]->next->next = new Node(11);
    lls[1] = new Node(3);
    lls[1]->next = new Node(10);
    lls[2] = new Node(2);
    lls[2]->next = new Node(8);
    lls[2]->next->next = new Node(13);
    lls[3] = new Node(5);
    lls[3]->next = new Node(9);
    lls[4] = new Node(1);
    lls[5] = new Node(6);
    lls[5]->next = new Node(12);
    print(merge_1(lls, 6));
    // print(merge_2(lls, 6));
    return 0;
}