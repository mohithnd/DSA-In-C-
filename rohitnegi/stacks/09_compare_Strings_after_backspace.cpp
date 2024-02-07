#include <iostream>
#include <stack>
using namespace std;

bool is_equal(string a, string b)
{
    stack<char> a1;
    for (char ch : a)
    {
        if (ch != '#')
        {
            a1.push(ch);
        }
        else
        {
            if (a1.empty() == false)
            {
                a1.pop();
            }
        }
    }
    stack<char> b1;
    for (char ch : b)
    {
        if (ch != '#')
        {
            b1.push(ch);
        }
        else
        {
            if (b1.empty() == false)
            {
                b1.pop();
            }
        }
    }
    return a1 == b1;
}

int main()
{
    string a = "ab#c";
    string b = "ad#c";
    cout << is_equal(a, b) << endl;
    return 0;
}