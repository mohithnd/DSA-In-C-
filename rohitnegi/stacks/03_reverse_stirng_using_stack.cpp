#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "Hello";
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        st.push(str[i]);
    }
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = st.top();
        st.pop();
    }
    cout << str << endl;
    return 0;
}