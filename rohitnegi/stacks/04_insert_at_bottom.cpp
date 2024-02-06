#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void insert_at_bottom(stack<int> &st, int ele)
{
    // time complexity: O(n)
    // space complexity: O(n)
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(ele);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);
    display(st);
    insert_at_bottom(st, 2);
    display(st);
    return 0;
}