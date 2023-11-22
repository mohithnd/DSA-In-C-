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
        this->next = NULL;
    }
};

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void remove(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head->next)
    {
        if (head->next->data == head->data)
        {
            Node *temp = head->next;
            head->next = head->next->next;
            delete temp;
        }
        else
        {
            head = head->next;
        }
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next->next = new Node(4);
    print(head);
    remove(head);
    print(head);
    return 0;
}