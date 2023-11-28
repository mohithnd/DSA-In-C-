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

Node *insert_at_head(Node *head, int data)
{
    Node *nodeToInsert = new Node(data);
    if (head == nullptr)
    {
        return nodeToInsert;
    }
    head->prev = nodeToInsert;
    nodeToInsert->next = head;
    return nodeToInsert;
}

Node *insert_at_end(Node *head, int data)
{
    Node *nodeToInsert = new Node(data);
    if (head == nullptr)
    {
        return nodeToInsert;
    }
    Node *temp = head;
    while (head->next)
    {
        head = head->next;
    }
    nodeToInsert->prev = head;
    head->next = nodeToInsert;
    return temp;
}

Node *insert_at_position(Node *head, int data, int k)
{
    Node *newNode = new Node(data);
    if (k == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node *curr = head;
    int cnt = 1;
    while (curr->next)
    {
        if (cnt == k)
        {
            newNode->next = curr;
            newNode->prev = curr->prev;
            curr->prev->next = newNode;
            curr->prev = newNode;
            return head;
        }
        curr = curr->next;
        cnt++;
    }
    curr->next = newNode;
    newNode->prev = curr;
    return head;
}

Node *insert_before_value(Node *head, int data, int value)
{
    Node *newNode = new Node(data);
    if (head->data == value)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node *curr = head;
    while (curr)
    {
        if (curr->data == value)
        {
            newNode->next = curr;
            newNode->prev = curr->prev;
            curr->prev->next = newNode;
            curr->prev = newNode;
            return head;
        }
        curr = curr->next;
    }
    return head;
}

int main()
{
    int arr[] = {2, 3, 1, 8};
    int n = sizeof(arr) / sizeof(int);
    Node *head = convertArrToDll(arr, n);
    traverse(head);
    head = insert_at_head(head, 4);
    traverse(head);
    head = insert_at_end(head, 10);
    traverse(head);
    head = insert_at_position(head, 100, 4);
    traverse(head);
    head = insert_before_value(head, 250, 10);
    traverse(head);
    return 0;
}