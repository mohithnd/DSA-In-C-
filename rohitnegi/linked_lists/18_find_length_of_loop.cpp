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

int loop_length_1(Node *head)
{
    map<Node *, int> m;
    int i = 0;
    while (head)
    {
        if (m.find(head) != m.end())
        {
            return i - m[head];
        }
        m[head] = i;
        i++;
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
            int i = 0;
            do
            {
                i++;
                slow = slow->next;
            } while (slow != fast);
            return i;
        }
    }
    return 0;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    cout << loop_length_1(head) << endl;
    cout << loop_length_2(head) << endl;
    head->next->next->next->next->next->next->next->next->next->next = head->next->next->next;
    cout << loop_length_1(head) << endl;
    cout << loop_length_2(head) << endl;
    return 0;
}