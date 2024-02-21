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

void make_circular_dll_from_arr(vector<int> arr, Node *&head, Node *&tail)
{
    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
    }
    tail->next = head;
    head->prev = tail;
}

void print(Node *head, Node *tail)
{
    if (head == nullptr)
    {
        cout << "Doubly LL Is Empty" << endl;
        return;
    }
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << "          ";
    ptr = tail;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    } while (ptr != tail);
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 10, 12, 7, 8};
    Node *head = nullptr;
    Node *tail = nullptr;
    make_circular_dll_from_arr(arr, head, tail);
    print(head, tail);
    return 0;
}