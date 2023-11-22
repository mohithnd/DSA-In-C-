#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *down;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};

void print(Node *head)
{
    vector<Node *> v;
    while (head)
    {
        v.push_back(head);
        head = head->next;
    }
    while (v.size())
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i])
            {
                cout << v[i]->data << " ";
                v[i] = v[i]->down;
            }
            else
            {
                cout << "  ";
            }
            if (v[v.size() - 1] == NULL)
            {
                v.pop_back();
            }
        }
        cout << endl;
    }
}

Node *flatten(Node *head)
{
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->down = new Node(2);
    head->down->down = new Node(3);

    head->next = new Node(4);
    head->next->down = new Node(5);
    head->next->down->down = new Node(6);

    head->next->next = new Node(7);
    head->next->next->down = new Node(8);

    head->next->next->next = new Node(9);
    head->next->next->next->down = new Node(12);

    head->next->next->next->next = new Node(20);

    print(head);
    head = flatten(head);
    print(head);
    return 0;
}