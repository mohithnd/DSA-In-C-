#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print(stack<int> st)
{
    if (st.empty())
    {
        cout << "Satck Is Empty" << endl;
        return;
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

string reverse_string(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        st.push(ch);
    }
    s.clear();
    while (st.empty() == false)
    {
        s.push_back(st.top());
        st.pop();
    }
    return s;
}

string valid_parentheses(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (st.empty())
            {
                return "Not Balanced";
            }
            else if ((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') || (st.top() == '{' && ch == '}'))
            {
                st.pop();
            }
            else
            {
                return "Not Balanced";
            }
        }
    }
    if (st.empty())
    {
        return "Balanced";
    }
    return "Not Balanced";
}

void insert_at_bottom_1(stack<int> &st, int ele)
{
    stack<int> other;
    while (!st.empty())
    {
        other.push(st.top());
        st.pop();
    }
    other.push(ele);
    while (!other.empty())
    {
        st.push(other.top());
        other.pop();
    }
}

void insert_at_bottom_2(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int n = st.top();
    st.pop();
    insert_at_bottom_2(st, ele);
    st.push(n);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom_2(st, ele);
}

void insert_at_sorted_position(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    if (ele >= st.top())
    {
        st.push(ele);
        return;
    }
    int data = st.top();
    st.pop();
    insert_at_sorted_position(st, ele);
    st.push(data);
}

void sort(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    sort(st);
    insert_at_sorted_position(st, ele);
}

int main()
{
    return 0;
}