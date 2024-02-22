#include <iostream>
#include <vector>
#include <map>
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

int intersection_node_1(Node *head1, Node *head2)
{
    map<Node *, bool> m;
    while (head1)
    {
        m[head1] = true;
        head1 = head1->next;
    }
    while (head2)
    {
        if (m[head2])
        {
            return head2->data;
        }
        head2 = head2->next;
    }
    return -1;
}

int length(Node *head)
{
    int len = 0;
    while (head)
    {
        head = head->next;
        len++;
    }
    return len;
}

int intersection_node_2(Node *head1, Node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);
    int diff = abs(len1 - len2);
    if (len1 > len2)
    {
        while (diff--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        while (diff--)
        {
            head2 = head2->next;
        }
    }
    while (head1 && head2)
    {
        if (head1 == head2)
        {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);

    Node *head2 = new Node(8);
    head2->next = new Node(9);
    head2->next->next = head1->next->next->next->next;

    print(head1);
    print(head2);
    cout << intersection_node_1(head1, head2) << endl;
    cout << intersection_node_2(head1, head2) << endl;
    return 0;
}