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

Node *swap_pairs_of_ll(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *fwd = head->next->next;
    Node *bwd = head->next;
    head->next->next = head;
    head->next = swap_pairs_of_ll(fwd);
    return bwd;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    print(head);
    head = swap_pairs_of_ll(head);
    print(head);
    return 0;
}