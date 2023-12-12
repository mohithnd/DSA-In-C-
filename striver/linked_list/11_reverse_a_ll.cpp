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

Node *reverse1(Node *head)
{
    // tc - o(n)
    // sc - o(n)
    // passes - 2
    stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node *reverse2(Node *head)
{
    // tc - o(n)
    // sc - o(1)
    // passes - 1
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

Node *reverse3(Node *head)
{
    // tc - o(n)
    // sc - o(n) (satck space)
    // passes - 1
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = reverse3(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    int arr[] = {2, 10, 3, 8, 5, 4};
    int n = sizeof(arr) / sizeof(int);
    Node *ll = convertArrToLL(arr, n);
    traverse(ll);
    // ll = reverse1(ll);
    // ll = reverse2(ll);
    ll = reverse3(ll);
    traverse(ll);
    return 0;
}