#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> st1;
    stack<int> st2;
    bool empty()
    {
        return st1.empty() && st2.empty();
    }
    void push(int data)
    {
        st1.push(data);
    }
    int pop()
    {
        if (empty())
        {
            cout << "Empty Queue" << endl;
            return -1;
        }
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ele = st2.top();
        st2.pop();
        return ele;
    }
    int front()
    {
        if (empty())
        {
            cout << "Empty Queue" << endl;
            return -1;
        }
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    int rear()
    {
        if (empty())
        {
            cout << "Empty Queue" << endl;
            return -1;
        }
        if (st1.empty())
        {
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        return st1.top();
    }
    int get_size()
    {
        return st1.size() + st2.size();
    }
    void display()
    {
        if (empty())
        {
            cout << "Empty Queue" << endl;
            return;
        }
        stack<int> s1 = st1;
        stack<int> s2 = st2;
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.push(5);
    q.push(15);
    q.push(51);
    q.push(125);
    q.push(6);
    q.pop();
    q.push(511);
    q.push(38);
    q.pop();
    cout << q.get_size() << endl;
    cout << q.front() << endl;
    cout << q.rear() << endl;
    q.display();
    return 0;
}