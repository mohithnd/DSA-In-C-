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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

int main()
{
    Node a = Node(4, nullptr);
    cout << a.data << endl;
    Node *b = new Node(6);
    cout << b->data << endl;
    return 0;
}