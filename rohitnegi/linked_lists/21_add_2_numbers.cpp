#include <iostream>
#include <vector>
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

Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *ans = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return ans;
}

Node *add(Node *num1, Node *num2)
{
    if (num1 == nullptr)
    {
        return num2;
    }
    if (num2 == nullptr)
    {
        return num1;
    }
    num1 = reverse(num1);
    num2 = reverse(num2);
    Node *ans = new Node(-1);
    Node *dummy = ans;
    int c = 0;
    while (num1 || num2)
    {
        int sum = c;
        if (num1)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2)
        {
            sum += num2->data;
            num2 = num2->next;
        }
        ans->next = new Node(sum % 10);
        c = sum / 10;
        ans = ans->next;
    }
    if (c)
    {
        ans->next = new Node(c);
        ans = ans->next;
    }
    return reverse(dummy->next);
}

int main()
{
    Node *num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(6);
    num1->next->next->next = new Node(8);
    num1->next->next->next->next = new Node(4);

    Node *num2 = new Node(6);
    num2->next = new Node(4);
    num2->next->next = new Node(3);
    num2->next->next->next = new Node(8);

    print(num1);
    print(num2);

    Node *sum = add(num1, num2);
    print(sum);
    return 0;
}