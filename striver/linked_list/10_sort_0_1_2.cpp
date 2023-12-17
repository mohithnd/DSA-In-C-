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
    // Time : O(2n) Space : O(1)
    int zero = 0, one = 0, two = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
        temp = temp->next;
    }
    temp = head;
    while (zero)
    {
        temp->data = 0;
        temp = temp->next;
        zero--;
    }
    while (one)
    {
        temp->data = 1;
        temp = temp->next;
        one--;
    }
    while (two)
    {
        temp->data = 2;
        temp = temp->next;
        two--;
    }
    return head;
}

Node *method2(Node *head)
{
    // Time : O(n) Space : O(1)
    Node *zero = new Node(-1);
    Node *one = new Node(-1);
    Node *two = new Node(-1);
    Node *zero_ptr = zero;
    Node *one_ptr = one;
    Node *two_ptr = two;
    while (head)
    {
        if (head->data == 0)
        {
            zero_ptr->next = head;
            head = head->next;
            zero_ptr = zero_ptr->next;
        }
        else if (head->data == 1)
        {
            one_ptr->next = head;
            head = head->next;
            one_ptr = one_ptr->next;
        }
        else
        {
            two_ptr->next = head;
            head = head->next;
            two_ptr = two_ptr->next;
        }
    }
    if (one->next)
    {
        zero_ptr->next = one->next;
        one_ptr->next = two->next;
        two_ptr->next = nullptr;
    }
    else
    {
        zero_ptr->next = two->next;
        two_ptr->next = nullptr;
    }
    return zero->next;
}

int main()
{
    int arr[] = {1, 0, 2, 1, 0, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToLL(arr, n);
    traverse(head);
    // head = method1(head);
    head = method2(head);
    traverse(head);
    return 0;
}