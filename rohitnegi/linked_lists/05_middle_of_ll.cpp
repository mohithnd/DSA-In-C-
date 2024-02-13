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

Node *find_middle_1(Node *head)
{
    int len = length(head);
    if (len == 0 || len == 1)
    {
        return head;
    }
    int cnt = 0;
    while (cnt < (len / 2))
    {
        head = head->next;
        cnt++;
    }
    return head;
}

Node *find_middle_2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    print(head);
    cout << find_middle_1(head)->data << endl;
    cout << find_middle_2(head)->data << endl;

    head->next->next->next->next->next = new Node(60);
    print(head);
    cout << find_middle_1(head)->data << endl;
    cout << find_middle_2(head)->data << endl;
    return 0;
}