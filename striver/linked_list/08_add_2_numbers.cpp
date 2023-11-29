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

Node *sum_of_ll_numbers(Node *num1, Node *num2)
{
    int c = 0;
    Node *ans = new Node(-1);
    Node *head = ans;
    while (num1 && num2)
    {
        int sum = num1->data + num2->data + c;
        c = sum / 10;
        ans->next = new Node(sum % 10);
        ans = ans->next;
        num1 = num1->next;
        num2 = num2->next;
    }
    while (num1)
    {
        int sum = num1->data + c;
        c = sum / 10;
        ans->next = new Node(sum % 10);
        ans = ans->next;
        num1 = num1->next;
    }
    while (num2)
    {
        int sum = num2->data + c;
        c = sum / 10;
        ans->next = new Node(sum % 10);
        ans = ans->next;
        num2 = num2->next;
    }
    while (c)
    {
        int sum = c;
        c = sum / 10;
        ans->next = new Node(sum % 10);
        ans = ans->next;
    }
    return head->next;
}

int main()
{
    int arr1[3] = {2, 4, 6};
    Node *num1 = convertArrToLL(arr1, 3);
    int arr2[3] = {3, 8, 7};
    Node *num2 = convertArrToLL(arr2, 3);
    traverse(num1);
    traverse(num2);
    Node *sum = sum_of_ll_numbers(num1, num2);
    traverse(sum);
    return 0;
}