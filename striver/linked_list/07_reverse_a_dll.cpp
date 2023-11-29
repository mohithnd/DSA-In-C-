#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void traverse(Node *head)
{
    if (head == nullptr)
    {
        cout << "DLL Is Empty" << endl;
        return;
    }
    Node *prev = head;
    while (head)
    {
        cout << head->data << " ";
        prev = head;
        head = head->next;
    }
    cout << "     ";
    while (prev)
    {
        cout << prev->data << " ";
        prev = prev->prev;
    }
    cout << endl;
}

Node *convertArrToDll(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *nodeToInsert = new Node(arr[i]);
        nodeToInsert->prev = head;
        head->next = nodeToInsert;
        head = head->next;
    }
    return temp;
}

Node *reverse1(Node *head)
{
    // TC - O(n)
    // SC - O(n)
    // Passes - 2
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
    // TC - O(n)
    // SC - O(1)
    Node *last = nullptr;
    while (head)
    {
        last = head->prev;
        head->prev = head->next;
        head->next = last;
        head = head->prev;
    }
    return last->prev;
}

int main()
{
    int arr[] = {2, 3, 1, 8, 4, 6, 5};
    int n = sizeof(arr) / sizeof(int);
    Node *head = convertArrToDll(arr, n);
    traverse(head);
    // head = reverse1(head);
    head = reverse2(head);
    traverse(head);
    return 0;
}