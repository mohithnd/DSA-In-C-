#include <iostream>
#include <queue>
using namespace std;

class Stack
{
public:
    queue<int> q1;
    queue<int> q2;
    bool empty()
    {
        return q1.empty() && q2.empty();
    }
    void push(int data)
    {
        if (!q1.empty())
        {
            q1.push(data);
        }
        else
        {
            q2.push(data);
        }
    }
    int top()
    {
        if (empty())
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
        if (!q1.empty())
        {
            return q1.back();
        }
        return q2.back();
    }
    int pop()
    {
        if (empty())
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
        if (!q1.empty())
        {
            int n = q1.size() - 1;
            for (int i = 0; i < n; i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
        int n = q2.size() - 1;
        for (int i = 0; i < n; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        int ele = q2.front();
        q2.pop();
        return ele;
    }
    int get_size()
    {
        return q1.size() + q2.size();
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.empty() << endl;
    cout << st.get_size() << endl;
    return 0;
}