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

Node *reverse_in_k_groups_1(Node *head, int k)
{
    Node *first = new Node(-1);
    first->next = head;
    head = first;
    while (first->next)
    {
        int x = k;
        Node *second = first->next;
        Node *prev = first;
        Node *curr = first->next;
        while (x && curr)
        {
            Node *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            x--;
        }
        first->next = prev;
        second->next = curr;
        first = second;
    }
    first = head;
    head = head->next;
    delete first;
    return head;
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next = new Node(11);

    print(head);
    head = reverse_in_k_groups_1(head, 4);
    print(head);
    return 0;
}