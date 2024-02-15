#include <iostream>
#include <vector>
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

void reverse_1(queue<int> &q)
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

void reverse_2(queue<int> &q)
{
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(7);
    q.push(11);
    q.push(8);
    q.push(9);
    print(q);
    reverse_1(q);
    print(q);
    reverse_2(q);
    print(q);
    return 0;
}