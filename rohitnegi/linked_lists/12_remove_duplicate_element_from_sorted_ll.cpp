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

Node *remove_duplicate_1(Node *head)
{
    vector<int> ans;
    Node *ptr = head;
    while (ptr)
    {
        if (ans.size() == 0)
        {
            ans.push_back(ptr->data);
        }
        else if (ans[ans.size() - 1] != ptr->data)
        {
            ans.push_back(ptr->data);
        }
        ptr = ptr->next;
    }
    ptr = head;
    Node *last = nullptr;
    for (int i = 0; i < ans.size(); i++)
    {
        ptr->data = ans[i];
        last = ptr;
        ptr = ptr->next;
    }
    last->next = nullptr;
    return head;
}

Node *remove_duplicate_2(Node *head)
{
    Node *prev = head;
    Node *curr = head->next;
    while (curr)
    {
        if (curr->data == prev->data)
        {
            prev->next = curr->next;
            Node *temp = curr;
            curr = prev->next;
            delete temp;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    print(head);
    // head = remove_duplicate_1(head);
    head = remove_duplicate_2(head);
    print(head);
    return 0;
}