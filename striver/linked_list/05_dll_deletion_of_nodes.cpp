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

Node *deletion_at_head(Node *head)
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
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

Node *deletion_at_end(Node *head)
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
    Node *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = nullptr;
    delete ptr;
    return head;
}

Node *deletion_at_position(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (k == 1 && head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }
    int cnt = 1;
    Node *temp = head;
    while (temp)
    {
        if (cnt == k)
        {
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
            else
            {
                temp->prev->next = nullptr;
                delete temp;
            }
            return head;
        }
        temp = temp->next;
        cnt++;
    }
    return head;
}

Node *deletion_at_value(Node *head, int value)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->data == value && head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }
    Node *temp = head;
    while (temp)
    {
        if (temp->data == value)
        {
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
            else
            {
                temp->prev->next = nullptr;
                delete temp;
            }
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    int arr[] = {2, 3, 1, 8, 4, 6, 5};
    int n = sizeof(arr) / sizeof(int);
    Node *head = convertArrToDll(arr, n);
    traverse(head);
    head = deletion_at_head(head);
    traverse(head);
    head = deletion_at_end(head);
    traverse(head);
    head = deletion_at_position(head, 5);
    traverse(head);
    head = deletion_at_value(head, 3);
    traverse(head);
    return 0;
}