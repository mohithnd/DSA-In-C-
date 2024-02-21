#include <iostream>
#include <vector>
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

void print(Node *head)
{
    if (head == nullptr)
    {
        cout << "LL Is Empty" << endl;
        return;
    }
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *merge_1(Node *head1, Node *head2)
{
    Node *ans = new Node(-1);
    Node *ptr = ans;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            ans->next = new Node(head1->data);
            head1 = head1->next;
            ans = ans->next;
        }
        else
        {
            ans->next = new Node(head2->data);
            head2 = head2->next;
            ans = ans->next;
        }
    }
    while (head1)
    {
        ans->next = new Node(head1->data);
        head1 = head1->next;
        ans = ans->next;
    }
    while (head2)
    {
        ans->next = new Node(head2->data);
        head2 = head2->next;
        ans = ans->next;
    }
    Node *temp = ptr;
    ptr = ptr->next;
    delete temp;
    return ptr;
}

Node *merge_2(Node *h1, Node *h2)
{
    Node *ans = new Node(-1);
    Node *ptr = ans;
    while (h1 && h2)
    {
        if (h1->data < h2->data)
        {
            ans->next = h1;
            h1 = h1->next;
            ans = ans->next;
        }
        else
        {
            ans->next = h2;
            h2 = h2->next;
            ans = ans->next;
        }
    }
    while (h1)
    {
        ans->next = h1;
        h1 = h1->next;
        ans = ans->next;
    }
    while (h2)
    {
        ans->next = h2;
        h2 = h2->next;
        ans = ans->next;
    }
    Node *temp = ptr;
    ptr = ptr->next;
    delete temp;
    return ptr;
}

int main()
{
    Node *head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    print(head1);

    Node *head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(4);
    head2->next->next->next = new Node(6);
    head2->next->next->next->next = new Node(8);
    head2->next->next->next->next->next = new Node(10);
    print(head2);

    // Node *ans = merge_1(head1, head2);
    Node *ans = merge_2(head1, head2);
    print(ans);
    return 0;
}