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

Node *remove_every_k_node(Node *head, int k)
{
    int cnt = 1;
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        if (cnt == k)
        {
            Node *temp = curr;
            prev->next = curr->next;
            curr = prev->next;
            cnt = 1;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
    }
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
    head = remove_every_k_node(head, 2);
    print(head);
    return 0;
}