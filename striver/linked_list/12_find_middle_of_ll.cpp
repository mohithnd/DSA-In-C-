#include <iostream>
#include <stack>
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
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

int middle_node_1(Node *head)
{
    // tc - O(n)
    // sc - O(1)
    // passes - 2
    int len = length(head);
    int mid = len / 2 + 1;
    int count = 1;
    while (count != mid)
    {
        head = head->next;
        count++;
    }
    return head->data;
}

int middle_node_2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    int arr[] = {2, 10, 3, 8, 5, 4};
    int n = sizeof(arr) / sizeof(int);
    Node *ll = convertArrToLL(arr, n);
    traverse(ll);
    cout << middle_node_1(ll) << endl;
    cout << middle_node_2(ll) << endl;
    return 0;
}