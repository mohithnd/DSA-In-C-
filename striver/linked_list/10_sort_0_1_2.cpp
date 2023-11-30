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

void traverse(Node *head)
{
    if (head == nullptr)
    {
        cout << "LL Is Empty" << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

Node *convertArrToLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *copy = head;
    for (int i = 1; i < n; i++)
    {
        copy->next = new Node(arr[i]);
        copy = copy->next;
    }
    return head;
}

Node *method1(Node *head)
{
    return head;
}

Node *method2(Node *head)
{
    return head;
}

int main()
{
    int arr[7] = {1, 0, 1, 2, 0, 2, 1};
    Node *head = convertArrToLL(arr, 7);
    traverse(head);
    head = method1(head);
    head = method2(head);
    traverse(head);
    return 0;
}