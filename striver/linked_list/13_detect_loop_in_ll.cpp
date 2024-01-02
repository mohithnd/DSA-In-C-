#include <iostream>
#include <stack>
#include <map>
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

void create_loop(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head->next->next->next;
}

bool detect_loop_1(Node *head)
{
    // Time Complexity: O(n*2logn)
    // Space Complexity: O(n)
    Node *temp = head;
    map<Node *, bool> m;
    while (temp)
    {
        if (m.find(temp) != m.end())
        {
            return true;
        }
        m[temp] = true;
        temp = temp->next;
    }
    return false;
}

bool detect_loop_2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *ll = convertArrToLL(arr, n);
    traverse(ll);
    cout << detect_loop_1(ll) << endl;
    cout << detect_loop_2(ll) << endl;
    create_loop(ll);
    cout << detect_loop_1(ll) << endl;
    cout << detect_loop_2(ll) << endl;
    return 0;
}