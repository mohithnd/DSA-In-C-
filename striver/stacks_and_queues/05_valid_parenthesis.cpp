#include <iostream>
#include <stack>
using namespace std;

bool balanced_parenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char top = st.top();
            if (top == '[' && s[i] == ']')
            {
                st.pop();
            }
            else if (top == '{' && s[i] == '}')
            {
                st.pop();
            }
            else if (top == '(' && s[i] == ')')
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
    string s = "()[{}()]";
    cout << balanced_parenthesis(s) << endl;
    s = "](){}";
    cout << balanced_parenthesis(s) << endl;
    return 0;
}