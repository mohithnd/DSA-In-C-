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

int length(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *middle1(Node *head)
{
    int len = length(head);
    int middleIndex = len / 2;
    int cnt = 0;
    while (cnt < middleIndex)
    {
        head = head->next;
        cnt++;
    }
    return head;
}

Node *middle2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
    }
    return slow;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    print(head);
    cout << middle1(head)->data << endl;
    cout << middle2(head)->data << endl;
    return 0;
}