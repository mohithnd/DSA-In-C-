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

bool is_palindrome_1(Node *head)
{
    // tc : O(n)
    // sc : O(n)
    // passes - 2
    stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    while (head)
    {
        if (head->data == st.top())
        {
            head = head->next;
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
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

bool is_palindrome_2(Node *head)
{
    // tc : O(n)
    // sc : O(1)
    // passes - 2
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = rev(slow->next);
    Node *first = head;
    Node *second = newHead;
    while (second)
    {
        if (first->data != second->data)
        {
            rev(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    rev(newHead);
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    Node *ll = convertArrToLL(arr, n);
    traverse(ll);
    cout << is_palindrome_1(ll) << endl;
    cout << is_palindrome_2(ll) << endl;
    traverse(ll);
    return 0;
}