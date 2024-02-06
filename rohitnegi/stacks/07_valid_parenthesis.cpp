#include <iostream>
#include <stack>
using namespace std;

bool is_valid_parenthesis(string str)
{
    stack<char> st;
    for (char ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if ((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') || (st.top() == '{' && ch == '}'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string str = "((())())";
    cout << is_valid_parenthesis(str) << endl;
    return 0;
}