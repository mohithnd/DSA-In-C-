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

Node *swap_pairs_of_ll(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *fwd = head->next->next;
    Node *bwd = head->next;
    head->next->next = head;
    head->next = swap_pairs_of_ll(fwd);
    return bwd;
}

Node *reverse_list_in_k_groups(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    int cnt = 0;
    while (cnt < k && curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    Node *rest_of_the_list = reverse_list_in_k_groups(curr, k);
    head->next = rest_of_the_list;
    return prev;
}

bool is_cycle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }
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

int middle_of_ll(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }
    if (head->next == nullptr)
    {
        return head->data;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << middle_of_ll(head) << endl;
    head->next->next->next->next->next = new Node(6);
    cout << middle_of_ll(head) << endl;
    return 0;
}