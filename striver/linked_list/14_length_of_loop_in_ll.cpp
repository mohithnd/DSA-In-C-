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

int loop_length_1(Node *head)
{
    map<Node *, int> m;
    int timer = 1;
    while (head)
    {
        if (m.find(head) != m.end())
        {
            return timer - m[head];
        }
        m[head] = timer;
        timer++;
        head = head->next;
    }
    return 0;
}

int loop_length_2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int len = 1;
            while (slow->next != fast)
            {
                slow = slow->next;
                len++;
            }
            return len;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *ll = convertArrToLL(arr, n);
    traverse(ll);
    cout << loop_length_1(ll) << endl;
    cout << loop_length_2(ll) << endl;
    create_loop(ll);
    cout << loop_length_1(ll) << endl;
    cout << loop_length_2(ll) << endl;
    return 0;
}