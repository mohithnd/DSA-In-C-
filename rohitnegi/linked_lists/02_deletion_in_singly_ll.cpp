#include <iostream>
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

Node *delete_at_start(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *new_head = head->next;
    delete head;
    return new_head;
}

Node *delete_at_end(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *ptr = head;
    Node *last = nullptr;
    while (ptr->next)
    {
        last = ptr;
        ptr = ptr->next;
    }
    last->next = nullptr;
    delete ptr;
    return head;
}

Node *delete_at_position(Node *head, int pos)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (pos <= 0)
    {
        Node *new_head = head->next;
        delete head;
        return new_head;
    }
    int cnt = 0;
    Node *ptr = head;
    Node *last = nullptr;
    while (cnt < pos && ptr)
    {
        last = ptr;
        ptr = ptr->next;
        cnt++;
    }
    if (ptr)
    {
        last->next = ptr->next;
        delete ptr;
    }
    return head;
}

Node *delete_at_position_using_recursion(Node *head, Node *last, int i, int pos)
{
    if (head == nullptr)
    {
        return head;
    }
    if (pos < 0)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *new_head = head->next;
        delete head;
        return new_head;
    }
    if (i == pos)
    {
        last->next = head->next;
        delete head;
        return last->next;
    }
    delete_at_position_using_recursion(head->next, head, i + 1, pos);
    return head;
}

int main()
{
    Node *head = new Node(20);
    head->next = new Node(8);
    head->next->next = new Node(7);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(5);
    print(head);
    head = delete_at_start(head);
    print(head);
    head = delete_at_end(head);
    print(head);
    head = delete_at_position(head, 3);
    print(head);
    head = delete_at_position_using_recursion(head, nullptr, 0, 2);
    print(head);
    return 0;
}