#include <iostream>
#include <queue>
using namespace std;

class Stack
{
public:
    queue<int> q1;
    queue<int> q2;
    int capacity;
    Stack()
    {
        this->capacity = 5;
    }
    bool empty()
    {
        return q1.empty();
    }
    bool full()
    {
        return q1.size() == capacity;
    }
    void push(int data)
    {
        if (this->full())
        {
            cout << "Stack is full" << endl;
            return;
        }
        q2.push(data);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop()
    {
        if (this->empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.pop();
    }
    int top()
    {
        if (this->empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }
    int size()
    {
        return q1.size();
    }
    void print_stack()
    {
        if (this->empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        queue<int> temp = q1;
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