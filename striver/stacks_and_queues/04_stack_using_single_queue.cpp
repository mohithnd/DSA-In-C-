#include <iostream>
#include <queue>
using namespace std;

class Stack
{
public:
    queue<int> q;
    int capacity;
    Stack()
    {
        this->capacity = 5;
    }
    bool empty()
    {
        return q.empty();
    }
    bool full()
    {
        return q.size() == capacity;
    }
    void push(int data)
    {
        if (this->full())
        {
            cout << "Stack is full" << endl;
            return;
        }
        q.push(data);
        int n = q.size();
        for (int i = 0; i < n - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (this->empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        q.pop();
    }
    int top()
    {
        if (this->empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }
    int size()
    {
        return q.size();
    }
    void print_stack()
    {
        if (this->empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        queue<int> temp = q;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(3);
    st.push(4);
    st.push(2);
    st.push(1);
    st.print_stack();
    st.pop();
    st.pop();
    st.pop();
    st.print_stack();
    st.push(5);
    st.print_stack();
    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;
    return 0;
}