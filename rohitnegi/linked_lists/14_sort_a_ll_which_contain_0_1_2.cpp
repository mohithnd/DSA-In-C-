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

Node *sort_1(Node *head)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    Node *ptr = head;
    while (ptr)
    {
        if (ptr->data == 0)
        {
            zero++;
        }
        else if (ptr->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
        ptr = ptr->next;
    }
    ptr = head;
    while (zero)
    {
        ptr->data = 0;
        zero--;
        ptr = ptr->next;
    }
    while (one)
    {
        one--;
        ptr->data = 1;
        ptr = ptr->next;
    }
    while (two)
    {
        two--;
        ptr->data = 2;
        ptr = ptr->next;
    }
    return head;
}

Node *sort_2(Node *head)
{
    Node *zero_head = new Node(-1);
    Node *zero_tail = zero_head;
    Node *one_head = new Node(-1);
    Node *one_tail = one_head;
    Node *two_head = new Node(-1);
    Node *two_tail = two_head;
    while (head)
    {
        if (head->data == 0)
        {
            zero_tail->next = head;
            zero_tail = zero_tail->next;
        }
        else if (head->data == 1)
        {
            one_tail->next = head;
            one_tail = one_tail->next;
        }
        else
        {
            two_tail->next = head;
            two_tail = two_tail->next;
        }
        head = head->next;
    }
    zero_tail->next = nullptr;
    one_tail->next = nullptr;
    two_tail->next = nullptr;
    if (one_head == one_tail)
    {
        zero_tail->next = two_head->next;
    }
    else
    {
        zero_tail->next = one_head->next;
        one_tail->next = two_head->next;
    }
    return zero_head->next;
}

int main()
{
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);
    print(head);
    // head = sort_1(head);
    head = sort_2(head);
    print(head);
    return 0;
}