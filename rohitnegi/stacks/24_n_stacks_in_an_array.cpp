#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = -1)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class NStack
{
public:
    int *arr;
    stack<int> st;
    Node **stacks;
    NStack(int N, int S)
    {
        arr = new int[S];
        for (int i = 0; i < S; i++)
        {
            st.push(i);
        }
        stacks = new Node *[N];
        for (int i = 0; i < N; i++)
        {
            stacks[i] = nullptr;
        }
    }

    bool push(int x, int m)
    {
        if (st.empty())
        {
            return false;
        }
        int ind = st.top();
        st.pop();
        arr[ind] = x;
        Node *temp = new Node(ind);
        temp->next = stacks[m - 1];
        stacks[m - 1] = temp;
        return true;
    }

    int pop(int m)
    {
        if (stacks[m - 1] == nullptr)
        {
            return -1;
        }
        Node *temp = stacks[m - 1];
        stacks[m - 1] = stacks[m - 1]->next;
        int ind = temp->data;
        st.push(ind);
        delete temp;
        return arr[ind];
    }
};

int main()
{
    NStack st(3, 6);
    cout << st.push(10, 1) << endl;
    cout << st.push(20, 1) << endl;
    cout << st.push(30, 2) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(2) << endl;
    return 0;
}