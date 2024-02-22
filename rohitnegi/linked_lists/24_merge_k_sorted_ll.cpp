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
        cout << "LL is empty" << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *merge(Node *h1, Node *h2)
{
    Node *ans = new Node(-1);
    Node *ptr = ans;
    while (h1 && h2)
    {
        if (h1->data < h2->data)
        {
            ans->next = h1;
            h1 = h1->next;
            ans = ans->next;
        }
        else
        {
            ans->next = h2;
            h2 = h2->next;
            ans = ans->next;
        }
    }
    while (h1)
    {
        ans->next = h1;
        h1 = h1->next;
        ans = ans->next;
    }
    while (h2)
    {
        ans->next = h2;
        h2 = h2->next;
        ans = ans->next;
    }
    Node *temp = ptr;
    ptr = ptr->next;
    delete temp;
    return ptr;
}

Node *merge_k_sorted_ll_1(vector<Node *> arr)
{
    Node *ans = nullptr;
    for (Node *ll : arr)
    {
        ans = merge(ans, ll);
    }
    return ans;
}

void merge_k_sorted_ll_2(vector<Node *> arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    merge_k_sorted_ll_2(arr, start, mid);
    merge_k_sorted_ll_2(arr, mid + 1, end);
    arr[start] = merge(arr[start], arr[mid + 1]);
}

int main()
{
    vector<Node *> arr(8, nullptr);
    arr[0] = new Node(1);
    arr[0]->next = new Node(2);
    arr[0]->next->next = new Node(4);

    arr[1] = new Node(3);
    arr[1]->next = new Node(6);

    arr[2] = new Node(4);
    arr[2]->next = new Node(5);
    arr[2]->next->next = new Node(9);
    arr[2]->next->next->next = new Node(10);

    arr[3] = new Node(7);

    arr[4] = new Node(6);
    arr[4]->next = new Node(8);

    arr[5] = new Node(2);
    arr[5]->next = new Node(7);
    arr[5]->next->next = new Node(8);
    arr[5]->next->next->next = new Node(10);

    arr[6] = new Node(17);
    arr[6]->next = new Node(19);
    arr[6]->next->next = new Node(22);

    arr[7] = new Node(4);
    arr[7]->next = new Node(18);

    // Node *ans = merge_k_sorted_ll_1(arr);
    merge_k_sorted_ll_2(arr, 0, arr.size() - 1);
    print(arr[0]);
    return 0;
}