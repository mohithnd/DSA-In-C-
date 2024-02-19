#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void print(Node *head, Node *tail)
{
    if (head == nullptr)
    {
        cout << "Doubly LL Is Empty" << endl;
        return;
    }
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "          ";
    while (tail)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

void insert_at_start(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insert_at_end(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void make_from_arr(vector<int> arr, Node *&head, Node *&tail)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (head == nullptr)
        {
            head = tail = new Node(arr[i]);
        }
        else
        {
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
}

void make_from_arr_recursive(vector<int> arr, Node *&head, Node *&tail, int index)
{
    if (index >= arr.size())
    {
        return;
    }
    Node *temp = new Node(arr[index]);
    if (head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    make_from_arr_recursive(arr, head, tail, index + 1);
}

void insert_at_position(Node *&head, Node *&tail, int pos, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data);
        return;
    }
    if (pos <= 0)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
    int cnt = 1;
    Node *ptr = head;
    while (cnt < pos && ptr)
    {
        cnt++;
        ptr = ptr->next;
    }
    Node *temp = new Node(data);
    if (ptr == nullptr)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    else
    {
        ptr->next->prev = temp;
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
    }
}

int main()
{
    // Node *a = new Node(10);
    // Node *b = new Node(20);
    // Node *c = new Node(30);
    // Node *d = new Node(40);
    // a->next = b;
    // b->next = c;
    // c->next = d;
    // d->prev = c;
    // c->prev = b;
    // b->prev = a;
    // Node *head = a;
    // Node *tail = d;
    // print(head, tail);
    // insert_at_start(head, tail, 5);
    // print(head, tail);
    // insert_at_end(head, tail, 12);
    // print(head, tail);

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = nullptr;
    Node *tail = nullptr;
    // make_from_arr(arr, head, tail);
    make_from_arr_recursive(arr, head, tail, 0);
    print(head, tail);
    insert_at_position(head, tail, 2, 44);
    print(head, tail);
    return 0;
}