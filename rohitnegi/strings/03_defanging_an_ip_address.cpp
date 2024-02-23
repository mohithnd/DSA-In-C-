#include <iostream>
using namespace std;

string defanging(string s)
{
    string ans = "";
    for (char ch : s)
    {
        if (ch == '.')
        {
            ans += "[.]";
        }
        else
        {
            ans += ch;
        }
    }
    return ans;
}

int main()
{
    string s = "1.1.1.1";
    cout << s << endl;
    s = defanging(s);
    cout << s << endl;
    return 0;
}