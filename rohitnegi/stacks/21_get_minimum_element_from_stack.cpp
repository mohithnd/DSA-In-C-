#include <iostream>
#include <stack>
using namespace std;

class MyStack1
{
public:
    stack<int> st1;
    stack<int> st2;
    void push(int x)
    {
        st1.push(x);
        if (st2.empty())
        {
            st2.push(x);
        }
        else
        {
            if (x < st2.top())
            {
                st2.push(x);
            }
            else
            {
                st2.push(st2.top());
            }
        }
    }
    void pop()
    {
        if (st1.empty() == false)
        {
            st1.pop();
            st2.pop();
        }
    }
    int top()
    {
        if (st1.empty() == false)
        {
            return st1.top();
        }
        return -1;
    }
    bool empty()
    {
        return st1.empty();
    }
    int getMin()
    {
        if (st2.empty())
        {
            return -1;
        }
        return st2.top();
    }
};

class MyStack2
{
public:
    stack<int> st;
    void push(int x)
    {
        if (st.empty())
        {
            int min = x;
            int curr = x;
            int n = curr * 101 + min;
            st.push(n);
        }
        else
        {
            int min = st.top() % 101;
            if (x < min)
            {
                min = x;
            }
            int curr = x;
            int n = curr * 101 + min;
            st.push(n);
        }
    }
    void pop()
    {
        if (st.empty() == false)
        {
            st.pop();
        }
    }
    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        return st.top() / 101;
    }
    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return st.top() % 101;
    }
    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    MyStack1 st;
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(26);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.push(34);
    cout << st.top() << endl;
    cout << st.getMin() << endl;

    cout << endl;

    MyStack2 st2;
    st2.push(2);
    st2.push(3);
    st2.push(1);
    st2.push(26);
    cout << st2.top() << endl;
    st2.pop();
    cout << st2.top() << endl;
    st2.push(34);
    cout << st2.top() << endl;
    cout << st2.getMin() << endl;
    return 0;
}