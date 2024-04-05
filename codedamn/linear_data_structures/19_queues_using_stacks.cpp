#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    int size;
    stack<int> s1;
    stack<int> s2;
    Queue(int size)
    {
        this->size = size;
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }

    bool full()
    {
        if (s1.size() + s2.size() == size)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (full())
        {
            cout << "Queue Is Full, Cannot Push" << endl;
            return;
        }
        s1.push(data);
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue Is Empty, Cannot Pop" << endl;
            return;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue Is Empty, Cannot Front" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    void print()
    {
        if (empty())
        {
            cout << "Queue Is Empty" << endl;
            return;
        }
        stack<int> temp;
        temp = s2;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        stack<int> temp2;
        temp2 = s1;
        while (!temp2.empty())
        {
            temp.push(temp2.top());
            temp2.pop();
        }
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    Queue q = Queue(5);
    q.print();
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.push(4);
    q.push(5);
    q.push(6);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.push(12);
    cout << q.front() << endl;
    q.print();
    return 0;
}