#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> st)
{
    if (st.empty())
    {
        cout << "Stack Is Empty" << endl;
        return;
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    print(st);
    st.pop();
    print(st);
    return 0;
}