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

void delete_without_head(Node *curr)
{
    Node *temp = curr->next;
    curr->data = temp->data;
    curr->next = temp->next;
    delete temp;
}

int main()
{
    Node *head = new Node(4);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(8);
    print(head);
    delete_without_head(head->next->next);
    print(head);
    return 0;
}