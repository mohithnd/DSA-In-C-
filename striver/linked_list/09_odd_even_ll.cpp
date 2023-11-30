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

Node *odd_even1(Node *head)
{
    return head;
}

Node *odd_even2(Node *head)
{
    return head;
}

int main()
{
    int arr[6] = {1, 3, 4, 2, 5, 6};
    Node *head = convertArrToLL(arr, 6);
    traverse(head);
    head = odd_even1(head);
    head = odd_even2(head);
    traverse(head);
    return 0;
}