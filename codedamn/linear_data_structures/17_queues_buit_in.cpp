#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void print(queue<int> q)
{
    if (q.empty())
    {
        cout << "Queue Is Empty" << endl;
        return;
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverse(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    print(q);
    reverse(q);
    print(q);
    return 0;
}