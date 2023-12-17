#include <iostream>
#include <vector>
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

Node *odd_even1(Node *head)
{
    // Time : O(2n) Space : O(n)
    vector<int> odd;
    vector<int> even;
    Node *temp = head;
    while (temp)
    {
        if (temp->data % 2 == 0)
        {
            even.push_back(temp->data);
        }
        else
        {
            odd.push_back(temp->data);
        }
        temp = temp->next;
    }
    temp = head;
    for (int i : even)
    {
        temp->data = i;
        temp = temp->next;
    }
    for (int i : odd)
    {
        temp->data = i;
        temp = temp->next;
    }
    return head;
}

Node *odd_even2(Node *head)
{
    // Time : O(n) Space : O(1)
    Node *odd = new Node(-1);
    Node *even = new Node(-1);
    Node *odd_ptr = odd;
    Node *even_ptr = even;
    while (head)
    {
        if (head->data % 2 == 0)
        {
            even_ptr->next = head;
            head = head->next;
            even_ptr = even_ptr->next;
        }
        else
        {
            odd_ptr->next = head;
            head = head->next;
            odd_ptr = odd_ptr->next;
        }
    }
    even_ptr->next = odd->next;
    odd_ptr->next = nullptr;
    return even->next;
}

int main()
{
    int arr[] = {6, 5, 3, 4, 7, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToLL(arr, n);
    traverse(head);
    // head = odd_even1(head);
    head = odd_even2(head);
    traverse(head);
    return 0;
}