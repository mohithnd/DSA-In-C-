#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "LL Is Empty" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

Node *merge(Node *left, Node *right)
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    Node *ans = new Node(-1);
    Node *dummy = ans;
    while (left && right)
    {
        if (left->data < right->data)
        {
            ans->bottom = left;
            left = left->bottom;
            ans = ans->bottom;
        }
        else
        {
            ans->bottom = right;
            right = right->bottom;
            ans = ans->bottom;
        }
    }
    while (left)
    {
        ans->bottom = left;
        left = left->bottom;
        ans = ans->bottom;
    }
    while (right)
    {
        ans->bottom = right;
        right = right->bottom;
        ans = ans->bottom;
    }
    return dummy->bottom;
}

Node *flatten_1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *left = head;
    Node *right = head->next;
    head->next = nullptr;
    right = flatten_1(right);
    return merge(left, right);
}

Node *flatten_2(Node *head)
{
    Node *head1, *head2, *head3;
    while (head->next)
    {
        head1 = head;
        head2 = head->next;
        head3 = head->next->next;

        head1->next = nullptr;
        head2->next = nullptr;

        head = merge(head1, head2);
        head->next = head3;
    }
    return head;
}

int main()
{
    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);
    head->next->bottom->bottom = new Node(40);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    head->next->next->next->next = new Node(30);
    head->next->next->next->next->bottom = new Node(34);
    head->next->next->next->next->bottom->bottom = new Node(40);

    // head = flatten_1(head);
    head = flatten_2(head);
    print(head);
    return 0;
}