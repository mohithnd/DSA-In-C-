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

int length(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

bool search(Node *head, int val)
{
    while (head != nullptr)
    {
        if (head->data == val)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

int main()
{
    int arr[] = {2, 1, 3, 8};
    int n = sizeof(arr) / sizeof(int);
    Node *ll = convertArrToLL(arr, n);
    traverse(ll);
    cout << length(ll) << endl;
    cout << search(ll, 1) << endl;
    cout << search(ll, 10) << endl;
    return 0;
}