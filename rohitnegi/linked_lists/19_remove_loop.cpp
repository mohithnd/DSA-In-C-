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

Node *remove_loop_1(Node *head)
{
    map<Node *, bool> m;
    Node *ptr = head;
    Node *last = nullptr;
    while (ptr)
    {
        if (m[ptr])
        {
            last->next = nullptr;
            break;
        }
        m[ptr] = true;
        last = ptr;
        ptr = ptr->next;
    }
    return head;
}

Node *remove_loop_2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr)
    {
        return head;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    while (slow->next != fast)
    {
        slow = slow->next;
    }
    slow->next = nullptr;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    head->next->next->next->next->next->next->next->next->next->next = head->next->next->next;
    // head = remove_loop_1(head);
    head = remove_loop_2(head);
    print(head);
    return 0;
}