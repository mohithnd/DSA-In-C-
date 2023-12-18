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

Node *rev(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = rev(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

Node *add_one_1(Node *head)
{
    // TC - O(3N)
    // SC - O(1)
    head = rev(head);
    int c = 1;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp && c)
    {
        int sum = temp->data + c;
        temp->data = sum % 10;
        c = sum / 10;
        prev = temp;
        temp = temp->next;
    }
    if (c)
    {
        prev->next = new Node(c);
    }
    return rev(head);
}

int helper(Node *head)
{
    if (head == nullptr)
    {
        return 1;
    }
    int carry = helper(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10;
}

Node *add_one_2(Node *head)
{
    int carry = helper(head);
    if (carry)
    {
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main()
{
    int arr[] = {9, 9, 9};
    // int arr[] = {1, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToLL(arr, n);
    traverse(head);
    // head = add_one_1(head);
    int carry = 0;
    head = add_one_2(head);
    traverse(head);
    return 0;
}