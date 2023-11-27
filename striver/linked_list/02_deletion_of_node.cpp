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

Node *deletion_of_head(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deletion_of_last(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *copy = head;
    while (copy->next->next != nullptr)
    {
        copy = copy->next;
    }
    Node *temp = copy->next;
    copy->next = nullptr;
    delete temp;
    return head;
}

Node *deletion_at_position(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 1;
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (cnt == k)
        {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    return head;
}

Node *deletion_at_value(Node *head, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->data == val)
        {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

int main()
{
    int arr[] = {2, 1, 3, 11, 7, 23, 5, 8};
    int n = sizeof(arr) / sizeof(int);
    Node *head = convertArrToLL(arr, n);
    traverse(head);
    head = deletion_of_head(head);
    traverse(head);
    head = deletion_of_last(head);
    traverse(head);
    head = deletion_at_position(head, 4);
    traverse(head);
    head = deletion_at_value(head, 23);
    traverse(head);
    return 0;
}