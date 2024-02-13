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

int length(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *rotate_1(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    int len = length(head);
    k = k % len;
    if (k == 0)
    {
        return head;
    }
    int cnt = 1;
    Node *ptr = head;
    Node *ans = nullptr;
    Node *last = nullptr;
    while (ptr->next)
    {
        if (cnt == len - k)
        {
            last = ptr;
            ans = ptr->next;
        }
        cnt++;
        ptr = ptr->next;
    }
    last->next = nullptr;
    ptr->next = head;
    return ans;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    print(head);
    head = rotate_1(head, 2);
    print(head);
    return 0;
}