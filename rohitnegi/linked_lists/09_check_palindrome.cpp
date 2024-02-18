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

bool palindrome_1(Node *head)
{
    vector<int> arr;
    while (head)
    {
        arr.push_back(head->data);
        head = head->next;
    }
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int length(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
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

bool palindrome_2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *curr = head;
    Node *last = nullptr;
    int cnt = 0;
    int len = length(head);
    while (cnt < (len / 2))
    {
        last = curr;
        curr = curr->next;
        cnt++;
    }
    last->next = nullptr;
    curr = reverse(curr);
    Node *ptr1 = head;
    Node *ptr2 = curr;
    while (ptr1 && ptr2)
    {
        if (ptr1->data != ptr2->data)
        {
            curr = reverse(curr);
            last->next = curr;
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    curr = reverse(curr);
    last->next = curr;
    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    print(head);
    cout << palindrome_1(head) << endl;
    cout << palindrome_2(head) << endl;
    return 0;
}