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
        this->next = NULL;
    }
};

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverse1(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

void reverse2(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    reverse2(head, curr->next, curr);
    curr->next = prev;
}

Node *reverse3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverse3(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = new Node(9);
    print(head);
    // head = reverse1(head);
    // reverse2(head, head, NULL);
    head = reverse3(head);
    print(head);
    return 0;
}