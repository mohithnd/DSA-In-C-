#include <iostream>
#include <map>
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

void remove1(Node *head)
{
    while (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            if (temp->next->data == head->data)
            {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
            else
            {
                temp = temp->next;
            }
        }
        head = head->next;
    }
}

void remove2(Node *head)
{
}

void remove3(Node *head)
{
    map<int, bool> m;
    while (head->next)
    {
        m[head->data] = true;
        if (m[head->next->data])
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
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(2);
    print(head);
    remove1(head);
    // remove2(head);
    // remove3(head);
    print(head);
    return 0;
}