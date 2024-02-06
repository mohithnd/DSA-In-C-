#include <iostream>
#include <stack>
using namespace std;

int minimum_add_to_make_parenthesis_valid(string str)
{
    int ans = 0;
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
                ans++;
            }
            else if ((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') || (st.top() == '{' && ch == '}'))
            {
                st.pop();
            }
            else
            {
                ans++;
            }
        }
    }
    ans += st.size();
    return ans;
}

int main()
{
    string str = "((())())";
    cout << minimum_add_to_make_parenthesis_valid(str) << endl;
    str = "(()";
    cout << minimum_add_to_make_parenthesis_valid(str) << endl;
    str = "(())))";
    cout << minimum_add_to_make_parenthesis_valid(str) << endl;
    return 0;
}