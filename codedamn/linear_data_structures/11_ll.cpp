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

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = nullptr;
    }

    bool empty()
    {
        return this->head == nullptr;
    }

    void insert(int data)
    {
        Node *node = new Node(data);
        if (empty())
        {
            this->head = node;
            return;
        }
        Node *temp = this->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
    }

    void print()
    {
        if (empty())
        {
            cout << "LL Is Empty" << endl;
            return;
        }
        Node *temp = this->head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.print();
    ll.insert(2);
    ll.insert(4);
    ll.print();
    return 0;
}