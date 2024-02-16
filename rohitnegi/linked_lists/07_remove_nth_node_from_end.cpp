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

Node *remove_nth_node_from_end(Node *head, int n)
{
    int len = length(head);
    int from_start = len - n;
    if (from_start == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *ptr = head;
    while (cnt < (from_start - 1))
    {
        cnt++;
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    print(head);
    head = remove_nth_node_from_end(head, 2);
    print(head);
    return 0;
}