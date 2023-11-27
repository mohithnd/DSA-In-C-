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

Node *insertion_at_head(Node *head, int data)
{
    Node *nodeToInsert = new Node(data);
    if (head == nullptr)
    {
        return nodeToInsert;
    }
    nodeToInsert->next = head;
    return nodeToInsert;
}

Node *insertion_at_end(Node *head, int data)
{
    Node *nodeToInsert = new Node(data);
    if (head == nullptr)
    {
        return nodeToInsert;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = nodeToInsert;
    return head;
}

Node *insertion_at_position(Node *head, int data, int k)
{
    Node *nodeToInsert = new Node(data);
    if (head == nullptr)
    {
        return nodeToInsert;
    }
    if (k == 1)
    {
        nodeToInsert->next = head;
        return nodeToInsert;
    }
    int cnt = 1;
    Node *curr = head;
    Node *prev = nullptr;
    while (curr)
    {
        if (cnt == k)
        {
            nodeToInsert->next = curr;
            prev->next = nodeToInsert;
            return head;
        }
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = nodeToInsert;
    return head;
}

Node *insertion_before_value(Node *head, int data, int val)
{
    Node *nodeToInsert = new Node(data);
    if (head == nullptr)
    {
        return nodeToInsert;
    }
    if (head->data == val)
    {
        nodeToInsert->next = head;
        return nodeToInsert;
    }
    Node *curr = head;
    Node *prev = nullptr;
    while (curr)
    {
        if (curr->data == val)
        {
            nodeToInsert->next = curr;
            prev->next = nodeToInsert;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = nodeToInsert;
    return head;
}

int main()
{
    int arr[] = {2, 3, 1, 8};
    int n = sizeof(arr) / sizeof(int);
    Node *head = convertArrToLL(arr, n);
    traverse(head);
    head = insertion_at_head(head, 4);
    traverse(head);
    head = insertion_at_end(head, 78);
    traverse(head);
    head = insertion_at_position(head, 34, 4);
    traverse(head);
    head = insertion_before_value(head, 100, 34);
    traverse(head);
    return 0;
}