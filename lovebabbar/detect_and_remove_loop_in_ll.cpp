#include <iostream>
#include <map >
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

bool cycle(Node *head)
{
    map<Node *, bool> m;
    while (head)
    {
        if (m[head])
        {
            return true;
        }
        m[head] = true;
        head = head->next;
    }
    return false;
}

Node *floyds_cycle_detection_algorithm(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

Node *starting_node1(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floyds_cycle_detection_algorithm(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node *starting_node2(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    map<Node *, bool> m;
    while (head)
    {
        if (m[head])
        {
            return head;
        }
        m[head] = true;
        head = head->next;
    }
    return NULL;
}

void removeLoop1(Node *head)
{
    map<Node *, bool> m;
    Node *prev = NULL;
    while (head)
    {
        if (m[head])
        {
            prev->next = NULL;
            return;
        }
        m[head] = true;
        prev = head;
        head = head->next;
    }
}

void removeLoop2(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *startOfLoop = starting_node2(head);
    Node *temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(6);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = head->next->next;
    cout << cycle(head) << endl;
    cout << floyds_cycle_detection_algorithm(head)->data << endl;
    cout << starting_node1(head)->data << endl;
    cout << starting_node2(head)->data << endl;
    // removeLoop1(head);
    removeLoop2(head);
    print(head);
    return 0;
}