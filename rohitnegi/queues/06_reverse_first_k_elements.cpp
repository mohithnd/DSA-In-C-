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

void reverse_first_k_1(queue<int> &q, int k)
{
    stack<int> st;
    int k2 = q.size() - k;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < k2; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(7);
    q.push(10);
    q.push(13);
    q.push(8);
    q.push(5);
    q.push(4);
    print(q);
    reverse_first_k_1(q, 3);
    print(q);
    return 0;
}