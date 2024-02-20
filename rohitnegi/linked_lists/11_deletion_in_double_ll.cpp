#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void print(Node *head, Node *tail)
{
    if (head == nullptr)
    {
        cout << "Doubly LL Is Empty" << endl;
        return;
    }
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "          ";
    while (tail)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

void deletion_at_start(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        cout << "Doubly LL Is Empty" << endl;
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        head = tail = nullptr;
        delete temp;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

void deletion_at_end(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        cout << "Doubly LL Is Empty" << endl;
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        head = tail = nullptr;
        delete temp;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

void deletion_at_position(Node *&head, Node *&tail, int pos)
{
    if (head == nullptr)
    {
        cout << "Doubly LL Is Empty" << endl;
        return;
    }
    if (pos < 0)
    {
        return;
    }
    if (pos == 0)
    {
        deletion_at_start(head, tail);
        return;
    }
    int cnt = 0;
    Node *ptr = head;
    while (cnt < pos && ptr)
    {
        cnt++;
        ptr = ptr->next;
    }
    if (ptr == nullptr)
    {
        return;
    }
    if (ptr->next == nullptr)
    {
        deletion_at_end(head, tail);
        return;
    }
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    delete ptr;
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;
    Node *head = a;
    Node *tail = d;
    print(head, tail);
    deletion_at_start(head, tail);
    print(head, tail);
    deletion_at_end(head, tail);
    print(head, tail);
    deletion_at_position(head, tail, 1);
    print(head, tail);
    deletion_at_position(head, tail, 0);
    print(head, tail);
    return 0;
}