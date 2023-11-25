#include <iostream>
using namespace std;

string method1(string address)
{
    string ans = "";
    for (char ch : address)
    {
        if (ch != '.')
        {
            ans += ch;
        }
        else
        {
            ans += '[';
            ans += ch;
            ans += ']';
        }
    }
    return ans;
}

int main()
{
    string address = "1.1.1.1";
    cout << method1(address) << endl;
    address = "255.100.25.60";
    cout << method1(address) << endl;
    return 0;
}