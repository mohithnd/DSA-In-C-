#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void traverse(Node *head)
{
    if (head == nullptr)
    {
        cout << "DLL Is Empty" << endl;
        return;
    }
    Node *prev = head;
    while (head)
    {
        cout << head->data << " ";
        prev = head;
        head = head->next;
    }
    cout << "     ";
    while (prev)
    {
        cout << prev->data << " ";
        prev = prev->prev;
    }
    cout << endl;
}

Node *convertArrToDll(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *nodeToInsert = new Node(arr[i]);
        nodeToInsert->prev = head;
        head->next = nodeToInsert;
        head = head->next;
    }
    return temp;
}

int main()
{
    int arr[] = {2, 3, 1, 8};
    int n = sizeof(arr) / sizeof(int);
    Node *head = convertArrToDll(arr, n);
    traverse(head);
    return 0;
}