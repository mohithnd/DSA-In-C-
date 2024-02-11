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

Node *create_using_insertion_at_start(int arr[], int n)
{
    Node *head = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (head == nullptr)
        {
            head = new Node(arr[i]);
        }
        else
        {
            Node *new_node = new Node(arr[i]);
            new_node->next = head;
            head = new_node;
        }
    }
    return head;
}

Node *create_using_insertion_at_end(int arr[], int n)
{
    Node *head = nullptr;
    Node *ans = head;
    for (int i = 0; i < n; i++)
    {
        if (head == nullptr)
        {
            head = new Node(arr[i]);
            ans = head;
        }
        else
        {
            head->next = new Node(arr[i]);
            head = head->next;
        }
    }
    return ans;
}

Node *create_using_insertion_at_end_using_recursion(int *arr, int i, int n)
{
    if (i >= n)
    {
        return nullptr;
    }
    Node *new_node = new Node(arr[i]);
    new_node->next = create_using_insertion_at_end_using_recursion(arr, i + 1, n);
    return new_node;
}

Node *create_using_insertion_at_start_using_recursion(Node *head, int *arr, int i, int n)
{
    Node *new_node = new Node(arr[i]);
    new_node->next = head;
    if (i == n - 1)
    {
        return new_node;
    }
    return create_using_insertion_at_start_using_recursion(new_node, arr, i + 1, n);
}

Node *insert_at_position(Node *head, int pos, int data)
{
    Node *new_node = new Node(data);
    if (pos <= 0)
    {
        new_node->next = head;
        return new_node;
    }
    if (head == nullptr)
    {
        return new_node;
    }
    Node *ptr = head;
    Node *last = nullptr;
    int cnt = 0;
    while (cnt < pos && ptr)
    {
        last = ptr;
        ptr = ptr->next;
        cnt++;
    }
    new_node->next = ptr;
    last->next = new_node;
    return head;
}

Node *insert_at_position_using_recursion(Node *head, Node *last, int i, int pos, int data)
{
    Node *new_node = new Node(data);
    if (pos <= 0)
    {
        new_node->next = head;
        return new_node;
    }
    if (head == nullptr)
    {
        if (last == nullptr)
        {
            return new_node;
        }
        last->next = new_node;
        return last;
    }
    if (i == pos)
    {
        new_node->next = head;
        last->next = new_node;
        return new_node;
    }
    insert_at_position_using_recursion(head->next, head, i + 1, pos, data);
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    Node *head1 = create_using_insertion_at_start(arr, n);
    print(head1);
    Node *head2 = create_using_insertion_at_end(arr, n);
    print(head2);
    Node *head3 = create_using_insertion_at_end_using_recursion(arr, 0, n);
    print(head3);
    Node *head4 = create_using_insertion_at_start_using_recursion(nullptr, arr, 0, n);
    print(head4);
    head4 = insert_at_position(head4, 3, 21);
    print(head4);
    head4 = insert_at_position_using_recursion(head4, nullptr, 0, 3, 9);
    print(head4);
    return 0;
}