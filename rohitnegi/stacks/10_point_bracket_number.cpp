#include <iostream>
#include <stack>
using namespace std;

string point_bracket_number(string str)
{
    string ans;
    int count = 0;
    stack<int> st;
    for (char ch : str)
    {
        if (ch == '(')
        {
            count++;
            st.push(count);
            ans += to_string(count);
        }
        else if (ch == ')')
        {
            ans += to_string(st.top());
            st.pop();
        }
    }
    return ans;
}

int main()
{
    string str = "(aa(bdc))p(de)";
    cout << point_bracket_number(str) << endl;
    return 0;
}