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
};

void print(Node *head)
{
    if (head == nullptr)
    {
        cout << "LL Is Empty" << endl;
        return;
    }
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverse_1(Node *head)
{
    vector<int> arr;
    Node *ptr = head;
    while (ptr)
    {
        arr.push_back(ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr)
    {
        ptr->data = arr[arr.size() - 1];
        ptr = ptr->next;
        arr.pop_back();
    }
    return head;
}

Node *reverse_2(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *fwd = nullptr;
    while (curr)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

Node *reverse_3(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *new_head = reverse_3(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    print(head);
    // head = reverse_1(head);
    // head = reverse_2(head);
    head = reverse_3(head);
    print(head);
    return 0;
}